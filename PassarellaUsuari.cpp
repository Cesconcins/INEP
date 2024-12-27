#include "PassarellaUsuari.h"

PassarellaUsuari::PassarellaUsuari(std::string sobrenom)
{
	try {
		sql::Connection* conn = open_connection();

		sql::Statement* stmt;
		stmt = conn->createStatement();

		std::string selectUserSQL = "SELECT * FROM inep21.usuari WHERE sobrenom='" + sobrenom + "';";

		sql::ResultSet* res = stmt->executeQuery(selectUserSQL);
		int count = 0;
        while (res->next()) {
            cout << res->getString("sobrenom") << endl;
        }
        close_connection(conn, stmt, res);
	} catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
}

std::string PassarellaUsuari::obteContrasenya()
{
	return "";
}