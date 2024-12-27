#include "DBConnection.h"

sql::Connection* open_connection()
{
    try {
        // Leer archivo de configuración JSON
        std::ifstream config_file("db_config.json");
        if (!config_file.is_open()) {
            throw std::runtime_error("No se pudo abrir el archivo de configuración.");
        }

        json config;
        config_file >> config;
        // Extraer datos de configuración
        std::string host = config["host"];
        int port = config["port"];
        std::string user = config["user"];
        std::string password = config["password"];
        std::string database = config["database"];

        sql::mysql::MySQL_Driver *driver = sql::mysql::get_mysql_driver_instance();
        sql::Connection* conn = driver->connect(host + ":" + std::to_string(port), user, password);
        // Seleccionar base de datos
        conn->setSchema("inep21");
        if (conn->isValid()) {
            std::cout << "Connection established successfully." << std::endl;
            return conn;
        }

    } catch (const sql::SQLException &e) {
        std::cerr << "Error SQL: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return nullptr;
}

void close_connection(sql::Connection *conn, sql::Statement* stmt, sql::ResultSet* res)
{
    try {
        delete conn;
        delete stmt;
        delete res;
    } catch (const sql::SQLException &e) {
        std::cerr << "Error SQL: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "Connection closed successfully." << std::endl;
}