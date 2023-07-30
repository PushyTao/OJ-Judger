#pragma once
#include <string>
#include "boost/asio.hpp"
#include "boost/asio/ssl.hpp"
#include "boost/mysql.hpp"

class MySQLConnector
{
public:
	MySQLConnector();

	MySQLConnector(const std::string& host_name, const std::string& port, const std::string& database_name,
		const std::string& user_name, const std::string& password);

	MySQLConnector(const MySQLConnector& other);

	MySQLConnector(MySQLConnector&& other) noexcept;

	MySQLConnector& operator=(const MySQLConnector& other);

	MySQLConnector& operator=(MySQLConnector&& other) noexcept;

	void getConnection() const;

	std::string hostName() const;

	void setHostName(const std::string& host_name);

	std::string port() const;

	void setPort(const std::string& port);

	std::string databaseName() const;

	void setDatabaseName(const std::string& database_name);

	std::string userName() const;

	void setUserName(const std::string& user_name);

	std::string password() const;

	void setPassword(const std::string& password);

private:
	std::string m_hostName;
	std::string m_port;
	std::string m_databaseName;
	std::string m_userName;
	std::string m_password;

};

