#include "MySQLConnector.h"

MySQLConnector::MySQLConnector()
{
}

MySQLConnector::MySQLConnector(const std::string& host_name, const std::string& port, const std::string& database_name,
                               const std::string& user_name, const std::string& password): m_hostName(host_name),
                                                                                           m_port(port),
                                                                                           m_databaseName(database_name),
                                                                                           m_userName(user_name),
                                                                                           m_password(password)
{
}

MySQLConnector::MySQLConnector(const MySQLConnector& other): m_hostName(other.m_hostName),
                                                             m_port(other.m_port),
                                                             m_databaseName(other.m_databaseName),
                                                             m_userName(other.m_userName),
                                                             m_password(other.m_password)
{
}

MySQLConnector::MySQLConnector(MySQLConnector&& other) noexcept: m_hostName(std::move(other.m_hostName)),
                                                                 m_port(std::move(other.m_port)),
                                                                 m_databaseName(std::move(other.m_databaseName)),
                                                                 m_userName(std::move(other.m_userName)),
                                                                 m_password(std::move(other.m_password))
{
}

MySQLConnector& MySQLConnector::operator=(const MySQLConnector& other)
{
	if (this == &other)
		return *this;
	m_hostName = other.m_hostName;
	m_port = other.m_port;
	m_databaseName = other.m_databaseName;
	m_userName = other.m_userName;
	m_password = other.m_password;
	return *this;
}

MySQLConnector& MySQLConnector::operator=(MySQLConnector&& other) noexcept
{
	if (this == &other)
		return *this;
	m_hostName = std::move(other.m_hostName);
	m_port = std::move(other.m_port);
	m_databaseName = std::move(other.m_databaseName);
	m_userName = std::move(other.m_userName);
	m_password = std::move(other.m_password);
	return *this;
}

void MySQLConnector::getConnection() const
{
	/*static boost::asio::io_context ctx;

	static boost::asio::ssl::context ssl_ctx(boost::asio::ssl::context::tls_client);
	
	static boost::mysql::tcp_ssl_connection conn(ctx.get_executor(), ssl_ctx);
	
	static boost::asio::ip::tcp::resolver resolver(ctx.get_executor());
	static const auto endpoints = resolver.resolve(m_hostName, m_port);

	static const boost::mysql::handshake_params params(
		m_userName,
		m_password,
		m_databaseName
	);
	
	conn.connect(*endpoints.begin(), params);*/
}

std::string MySQLConnector::hostName() const
{
	return m_hostName;
}

void MySQLConnector::setHostName(const std::string& host_name)
{
	m_hostName = host_name;
}

std::string MySQLConnector::port() const
{
	return m_port;
}

void MySQLConnector::setPort(const std::string& port)
{
	m_port = port;
}

std::string MySQLConnector::databaseName() const
{
	return m_databaseName;
}

void MySQLConnector::setDatabaseName(const std::string& database_name)
{
	m_databaseName = database_name;
}

std::string MySQLConnector::userName() const
{
	return m_userName;
}

void MySQLConnector::setUserName(const std::string& user_name)
{
	m_userName = user_name;
}

std::string MySQLConnector::password() const
{
	return m_password;
}

void MySQLConnector::setPassword(const std::string& password)
{
	m_password = password;
}
