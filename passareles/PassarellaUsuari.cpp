#include "PassarellaUsuari.h"

PassarellaUsuari::PassarellaUsuari(std::string sobrenom)
{
	try {
		sql::Connection* conn = open_connection();

		sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT * FROM inep21.usuari WHERE sobrenom = ?");
		pstmt->setString(1, sobrenom);

		sql::ResultSet* res = pstmt->executeQuery();

        while (res->next()) {
            this-> sobrenom = res->getString("sobrenom");
            this-> nom = res->getString("nom");
            this-> contrasenya = res->getString("contrasenya");
            this-> correuElectronic = res->getString("correu_electronic");
            
            // Parse the datetime string
            std::string datetimeStr = res->getString("data_naixement");
            std::istringstream ss(datetimeStr);
            std::tm tm = {};
            ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");

            if (ss.fail()) {
                std::cerr << "Failed to parse datetime: " << datetimeStr << std::endl;
                this->dataNaixement = static_cast<time_t>(-1); // Set an invalid time
            } else {
                this->dataNaixement = std::mktime(&tm); // Convert to time_t
            }

            this-> modalitatSubscripcio = res->getString("subscripcio");
        }
        close_connection(conn, pstmt, res);
	} catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

PassarellaUsuari::PassarellaUsuari(std::string sobrenom, std::string nom, std::string contrasenya, std::string correuElectronic, std::time_t dataNaixement, std::string modalitatSubscripcio)
{
	this->sobrenom = sobrenom;
	this->nom = nom;
	this->contrasenya = contrasenya;
	this->correuElectronic = correuElectronic;
	this->dataNaixement = dataNaixement;
	this->modalitatSubscripcio = modalitatSubscripcio;
}

PassarellaUsuari::~PassarellaUsuari() {}

std::string PassarellaUsuari::obteSobrenom()
{
	return this->sobrenom;
}

std::string PassarellaUsuari::obteNom()
{
	return this->nom;
}

std::string PassarellaUsuari::obteContrasenya()
{
	return this->contrasenya;
}

std::string PassarellaUsuari::obteCorreuElectronic()
{
	return this->correuElectronic;
}

std::time_t PassarellaUsuari::obteDataNaixement()
{
	return this->dataNaixement;
}

std::string PassarellaUsuari::obteModalitatSubscripcio()
{
	return this->modalitatSubscripcio;
}

int PassarellaUsuari::insereix()
{
	try {
		sql::Connection* conn = open_connection();

		sql::PreparedStatement* pstmt_sobrenom = conn->prepareStatement("SELECT * FROM inep21.usuari WHERE sobrenom = ?");
		pstmt_sobrenom->setString(1, this->sobrenom);
		sql::ResultSet* res_sobrenom = pstmt_sobrenom->executeQuery();

        if (res_sobrenom->next()) {
            close_connection(conn, pstmt_sobrenom, res_sobrenom);
            return -10;
        }
		
		sql::PreparedStatement* pstmt_correu = conn->prepareStatement("SELECT * FROM inep21.usuari WHERE correu_electronic = ?");
		pstmt_correu->setString(1, this->correuElectronic);
		sql::ResultSet* res_correu = pstmt_correu->executeQuery();

        if (res_correu->next()) {
            close_connection(conn, pstmt_correu, res_correu);
            return -20;
        }

		
		sql::PreparedStatement* pstmt_modalitat = conn->prepareStatement("SELECT * FROM inep21.modalitat_subscripcio WHERE nom = ?");
		pstmt_modalitat->setString(1, this->modalitatSubscripcio);
		sql::ResultSet* res_modalitat = pstmt_modalitat->executeQuery();

        if (!res_modalitat->next()) {
            close_connection(conn, pstmt_modalitat, res_modalitat);
            return -30;
        }
        
        sql::SQLString fechaSQL = timeToSQLString(this->dataNaixement);
        
		sql::PreparedStatement* pstmt_insert = conn->prepareStatement("INSERT INTO inep21.usuari(sobrenom, nom, contrasenya, correu_electronic, data_naixement, subscripcio) VALUES (?, ?, ?, ?, ?, ?)");
		pstmt_insert->setString(1, this->sobrenom);
		pstmt_insert->setString(2, this->nom);
		pstmt_insert->setString(3, this->contrasenya);
		pstmt_insert->setString(4, this->correuElectronic);
		pstmt_insert->setString(5, fechaSQL);
		pstmt_insert->setString(6, this->modalitatSubscripcio);
		
		pstmt_insert->executeUpdate();

        close_connection(conn, nullptr, nullptr);
	} catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
    return 0;
}

sql::SQLString PassarellaUsuari::timeToSQLString(time_t t) {
    // Convierte time_t a tm (estructura de tiempo)
    struct tm *timeinfo;
    timeinfo = localtime(&t);

    // Crea un string con el formato deseado (en este caso "YYYY-MM-DD HH:MM:SS")
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);

    // Devuelve el resultado como un sql::SQLString
    return sql::SQLString(buffer);
}

//SQL Error: Unknown column 'subscripcio' in 'where clause'

