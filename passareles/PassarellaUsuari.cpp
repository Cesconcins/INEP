#include "PassarellaUsuari.h"

PassarellaUsuari::PassarellaUsuari(std::string sobrenom)
{
	try
	{
		sql::Connection *conn = open_connection();

		sql::PreparedStatement *pstmt = conn->prepareStatement("SELECT * FROM inep21.usuari WHERE sobrenom = ?");
		pstmt->setString(1, sobrenom);

		sql::ResultSet *res = pstmt->executeQuery();

		while (res->next())
		{
			this->sobrenom = res->getString("sobrenom");
			this->nom = res->getString("nom");
			this->contrasenya = res->getString("contrasenya");
			this->correuElectronic = res->getString("correu_electronic");
			// parse date time
			std::string datetime = res->getString("data_naixement");
			size_t spacePos = datetime.find(' ');
			this->dataNaixement = datetime.substr(0, spacePos);
			this->modalitatSubscripcio = res->getString("subscripcio");
		}
		close_connection(conn, pstmt, res);
	}
	catch (sql::SQLException &e)
	{
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}

PassarellaUsuari::PassarellaUsuari(std::string nom, std::string sobrenom, std::string contrasenya, std::string correuElectronic, std::string dataNaixement, std::string modalitatSubscripcio)
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

std::string PassarellaUsuari::obteDataNaixement()
{
	return this->dataNaixement;
}

std::string PassarellaUsuari::obteModalitatSubscripcio()
{
	return this->modalitatSubscripcio;
}

void PassarellaUsuari::posaNom(std::string nom)
{
	this->nom = nom;
}

void PassarellaUsuari::posaContrasenya(std::string contrasenya)
{
	this->contrasenya = contrasenya;
}

void PassarellaUsuari::posaCorreuElectronic(std::string correuElectronic)
{
	this->correuElectronic = correuElectronic;
}

void PassarellaUsuari::posaDataNaixement(std::string dataNaixement)
{
	this->dataNaixement = dataNaixement;
}

void PassarellaUsuari::posaModalitat(std::string modalitatSubscripcio)
{
	this->modalitatSubscripcio = modalitatSubscripcio;
}

int PassarellaUsuari::insereix()
{
	try
	{
		sql::Connection *conn = open_connection();

		sql::PreparedStatement *pstmt_sobrenom = conn->prepareStatement("SELECT * FROM inep21.usuari WHERE sobrenom = ?");
		pstmt_sobrenom->setString(1, this->sobrenom);
		sql::ResultSet *res_sobrenom = pstmt_sobrenom->executeQuery();

		if (res_sobrenom->next())
		{
			close_connection(conn, pstmt_sobrenom, res_sobrenom);
			return -10;
		}

		sql::PreparedStatement *pstmt_correu = conn->prepareStatement("SELECT * FROM inep21.usuari WHERE correu_electronic = ?");
		pstmt_correu->setString(1, this->correuElectronic);
		sql::ResultSet *res_correu = pstmt_correu->executeQuery();

		if (res_correu->next())
		{
			close_connection(conn, pstmt_correu, res_correu);
			return -20;
		}

		sql::PreparedStatement *pstmt_modalitat = conn->prepareStatement("SELECT * FROM inep21.modalitat_subscripcio WHERE nom = ?");
		pstmt_modalitat->setString(1, this->modalitatSubscripcio);
		sql::ResultSet *res_modalitat = pstmt_modalitat->executeQuery();

		if (!res_modalitat->next())
		{
			close_connection(conn, pstmt_modalitat, res_modalitat);
			return -30;
		}

		std::string sqlSafe = this->dataNaixement;
		if (!isDateValid(this->dataNaixement))
			sqlSafe = convertToSQLDate(this->dataNaixement);
		sql::PreparedStatement *pstmt_insert = conn->prepareStatement("INSERT INTO inep21.usuari(sobrenom, nom, contrasenya, correu_electronic, data_naixement, subscripcio) VALUES (?, ?, ?, ?, ?, ?)");

		pstmt_insert->setString(1, this->sobrenom);
		pstmt_insert->setString(2, this->nom);
		pstmt_insert->setString(3, this->contrasenya);
		pstmt_insert->setString(4, this->correuElectronic);
		pstmt_insert->setString(5, sqlSafe);
		pstmt_insert->setString(6, this->modalitatSubscripcio);

		pstmt_insert->executeUpdate();

		close_connection(conn, nullptr, nullptr);
	}
	catch (sql::SQLException &e)
	{
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
	return 0;
}

bool PassarellaUsuari::modifica()
{
	try
	{
		sql::Connection *conn = open_connection();
		sql::PreparedStatement *pstmt = conn->prepareStatement("SELECT sobrenom, correu_electronic FROM inep21.usuari WHERE correu_electronic  = ?");
		pstmt->setString(1, this->correuElectronic);

		sql::ResultSet *res = pstmt->executeQuery();

		if (res->next())
		{
			std::string sobrenom = res->getString("sobrenom");
			if (sobrenom != this->sobrenom)
			{
				close_connection(conn, pstmt, res);
				return false;
			}
		}

		close_connection(conn, pstmt, res);

		if (!this->nom.empty())
		{
			sql::Connection *conn = open_connection();

			sql::PreparedStatement *pstmt_nom = conn->prepareStatement("UPDATE inep21.usuari SET nom = ? WHERE sobrenom = ?");
			pstmt_nom->setString(1, this->nom);
			pstmt_nom->setString(2, this->sobrenom);
			pstmt_nom->executeQuery();

			close_connection(conn, pstmt_nom, nullptr);
		}

		if (!this->contrasenya.empty())
		{
			sql::Connection *conn = open_connection();

			sql::PreparedStatement *pstmt_contr = conn->prepareStatement("UPDATE inep21.usuari SET contrasenya = ? WHERE sobrenom = ?");
			pstmt_contr->setString(1, this->contrasenya);
			pstmt_contr->setString(2, this->sobrenom);
			pstmt_contr->executeQuery();
			close_connection(conn, pstmt_contr, nullptr);
		}

		if (!this->correuElectronic.empty())
		{
			sql::Connection *conn = open_connection();

			sql::PreparedStatement *pstmt_correu = conn->prepareStatement("UPDATE inep21.usuari SET correu_electronic = ? WHERE sobrenom = ?");
			pstmt_correu->setString(1, this->correuElectronic);
			pstmt_correu->setString(2, this->sobrenom);
			pstmt_correu->executeQuery();

			close_connection(conn, pstmt_correu, nullptr);
		}

		if (!this->dataNaixement.empty())
		{
			sql::Connection *conn = open_connection();

			std::string sqlSafe = this->dataNaixement;
			if (!isDateValid(this->dataNaixement))
				sqlSafe = convertToSQLDate(this->dataNaixement);
			sql::PreparedStatement *pstmt_data = conn->prepareStatement("UPDATE inep21.usuari SET data_naixement = ? WHERE sobrenom = ?");
			pstmt_data->setString(1, sqlSafe);
			pstmt_data->setString(2, this->sobrenom);
			pstmt_data->executeQuery();

			close_connection(conn, pstmt_data, nullptr);
		}

		if (!this->modalitatSubscripcio.empty())
		{
			sql::Connection *conn = open_connection();

			sql::PreparedStatement *pstmt_sub = conn->prepareStatement("UPDATE inep21.usuari SET subscripcio = ? WHERE sobrenom = ?");
			pstmt_sub->setString(1, this->modalitatSubscripcio);
			pstmt_sub->setString(2, this->sobrenom);
			pstmt_sub->executeQuery();

			close_connection(conn, pstmt_sub, nullptr);
		}
	}
	catch (sql::SQLException &e)
	{
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
	return true;
}

void PassarellaUsuari::esborra()
{
	try
	{
		sql::Connection *conn = open_connection();
		sql::PreparedStatement *pstmt = conn->prepareStatement("DELETE FROM `inep21`.`usuari` WHERE (`sobrenom` = ?)");
		pstmt->setString(1, this->sobrenom);

		sql::ResultSet *res = pstmt->executeQuery();

		close_connection(conn, pstmt, res);
	}
	catch (sql::SQLException &e)
	{
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}

std::string PassarellaUsuari::convertToSQLDate(const std::string &date)
{
	if (date.length() != 10 || date[2] != '/' || date[5] != '/')
	{
		throw std::invalid_argument("Invalid date format. Expected DD/MM/YYYY.");
	}

	std::string day = date.substr(0, 2);
	std::string month = date.substr(3, 2);
	std::string year = date.substr(6, 4);

	return year + "-" + month + "-" + day; // Convert to YYYY-MM-DD
}

bool PassarellaUsuari::isDateValid(const std::string &date)
{
	// Regex pattern for YYYY-MM-DD format
	std::regex pattern(R"(\d{4}-\d{2}-\d{2})");
	return std::regex_match(date, pattern);
}