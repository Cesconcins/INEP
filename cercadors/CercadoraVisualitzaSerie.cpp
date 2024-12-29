#include "CercadoraVisualitzaSerie.h"

CercadoraVisualitzaSerie::CercadoraVisualitzaSerie() {}

int CercadoraVisualitzaSerie::cercaVisualitzacions(std::string sobrenom)
{
    int result = 0;
    try
    {
        sql::Connection *conn = open_connection();

        sql::PreparedStatement *pstmt = conn->prepareStatement("SELECT COUNT(titol_serie) FROM inep21.visualitzacio_capitol WHERE sobrenom_usuari = ?");
        pstmt->setString(1, sobrenom);

        sql::ResultSet *res = pstmt->executeQuery();

        if (res->next())
            result = res->getInt(1);
        close_connection(conn, pstmt, res);
    }
    catch (sql::SQLException &e)
    {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
    return result;
}