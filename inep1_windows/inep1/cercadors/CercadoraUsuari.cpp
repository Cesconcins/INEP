#include "CercadoraUsuari.h"

CercadoraUsuari::CercadoraUsuari() {}

Usuari CercadoraUsuari::cercaUsuari(std::string sobrenomU)
{
	try
	{
		sql::Connection *conn = open_connection();

		sql::PreparedStatement *pstmt = conn->prepareStatement("SELECT * FROM inep21.usuari WHERE sobrenom = ?");
		pstmt->setString(1, sobrenomU);

		sql::ResultSet *res = pstmt->executeQuery();

		while (res->next())
		{
			std::string sobrenom = res->getString("sobrenom");
			std::string nom = res->getString("nom");
			std::string correuElectronic = res->getString("correu_electronic");
			// parse date time
			std::string datetime = res->getString("data_naixement");
			size_t spacePos = datetime.find(' ');
			std::string dataNaixement = datetime.substr(0, spacePos);

			std::string modalitat = res->getString("subscripcio");
			Usuari u(sobrenom, nom, correuElectronic, dataNaixement, modalitat);
			return u;
			close_connection(conn, pstmt, res);
		}
	}
	catch (sql::SQLException &e)
	{
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
	Usuari empty_u;
	return empty_u;
}