
//#include "boost/mysql.hpp"
#include "iostream"
#include "boost/asio.hpp"
#include "boost/asio/ssl.hpp"
#include "boost/mysql.hpp"

int main(int argc, char* argv[])
{
	// The execution context, required to run I/O operations.
	boost::asio::io_context ctx;

	// The SSL context, required to establish TLS connections.
	// The default SSL options are good enough for us at this point.
	boost::asio::ssl::context ssl_ctx(boost::asio::ssl::context::tls_client);

	// Represents a connection to the MySQL server.
	boost::mysql::tcp_ssl_connection conn(ctx.get_executor(), ssl_ctx);

	// Resolve the hostname to get a collection of endpoints
	boost::asio::ip::tcp::resolver resolver(ctx.get_executor());
	auto endpoints = resolver.resolve(argv[3], boost::mysql::default_port_string);

	// The username, password and database to use
	boost::mysql::handshake_params params(
		argv[1],                // username
		argv[2],                // password
		"yggl"  // database
	);

	// Connect to the server using the first endpoint returned by the resolver
	conn.connect(*endpoints.begin(), params);

	// Issue the SQL query to the server
	const char* sql = "SELECT * from admin";
	boost::mysql::results result;
	conn.query(sql, result);

	// Print the first field in the first row
	std::cout << result.rows().at(0).at(0) << std::endl;

	const auto rowCount = result.rows().size();
	const auto colCount = result.rows().num_columns();
	for(auto i = 0; i < rowCount; ++i)
	{
		for(auto j = 0; j < colCount; ++ j)
		{
			std::cout << result.rows().at(i).at(j) << "  ";
		}
		std::cout << std::endl;
	}
	// Close the connection
	conn.close();

	return 0;
}