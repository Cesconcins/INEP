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

sql::ResultSet* fetchMovieDetails(const std::string& title) {
    try {
        sql::Connection* conn = open_connection();
        sql::PreparedStatement* pstmt = conn->prepareStatement(
            "SELECT * FROM pelicula WHERE titol = ?");
        pstmt->setString(1, title);
        sql::ResultSet* res = pstmt->executeQuery();
        return res; // Caller must close this ResultSet.
    } catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        return nullptr;
    }
}

void recordMovieVisualization(const std::string& userNickname, const std::string& title) {
    try {
        sql::Connection* conn = open_connection();
        sql::PreparedStatement* pstmt = conn->prepareStatement(
            "INSERT INTO visualitzacio_pelicula (sobrenom_usuari, titol_pelicula, data_visualitzacio, num_visualitzacions) "
            "VALUES (?, ?, NOW(), 1) "
            "ON DUPLICATE KEY UPDATE num_visualitzacions = num_visualitzacions + 1");
        pstmt->setString(1, userNickname);
        pstmt->setString(2, title);
        pstmt->executeUpdate();
        close_connection(conn, nullptr, nullptr);
    } catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

sql::ResultSet* DBConnection::fetchSeasons(const std::string& seriesTitle) {
    try {
        sql::Connection* conn = open_connection();
        sql::PreparedStatement* pstmt = conn->prepareStatement(
            "SELECT numero FROM temporada WHERE titol_serie = ?");
        pstmt->setString(1, seriesTitle);
        return pstmt->executeQuery(); // Caller must close the ResultSet.
    } catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        return nullptr;
    }
}

sql::ResultSet* DBConnection::fetchEpisodes(const std::string& seriesTitle, int seasonNumber) {
    try {
        sql::Connection* conn = open_connection();
        sql::PreparedStatement* pstmt = conn->prepareStatement(
            "SELECT numero, titol, data_estrena FROM capitol WHERE titol_serie = ? AND numero_temporada = ? ORDER BY numero DESC");
        pstmt->setString(1, seriesTitle);
        pstmt->setInt(2, seasonNumber);
        return pstmt->executeQuery(); // Caller must close the ResultSet.
    } catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
        return nullptr;
    }
}

void DBConnection::recordEpisodeVisualization(const std::string& userNickname, const std::string& seriesTitle, int seasonNumber, int episodeNumber) {
    try {
        sql::Connection* conn = open_connection();
        sql::PreparedStatement* pstmt = conn->prepareStatement(
            "INSERT INTO visualitzacio_capitol (sobrenom_usuari, titol_serie, numero_temporada, numero, data_visualitzacio, num_visualitzacions) "
            "VALUES (?, ?, ?, ?, NOW(), 1) "
            "ON DUPLICATE KEY UPDATE num_visualitzacions = num_visualitzacions + 1");
        pstmt->setString(1, userNickname);
        pstmt->setString(2, seriesTitle);
        pstmt->setInt(3, seasonNumber);
        pstmt->setInt(4, episodeNumber);
        pstmt->executeUpdate();
        close_connection(conn, nullptr, nullptr);
    } catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}
