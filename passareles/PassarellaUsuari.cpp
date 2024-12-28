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
        close_connection(conn, nullptr, res);
	} catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
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