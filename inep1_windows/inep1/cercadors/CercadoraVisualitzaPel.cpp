#include "CercadoraVisualitzaPel.h"

CercadoraVisualitzaPeli::CercadoraVisualitzaPeli()
{
}

CercadoraVisualitzaPeli::CercadoraVisualitzaPeli(string sobrenom)
{
    try
    {
        sql::Connection *conn = open_connection();

        sql::PreparedStatement *pstmt = conn->prepareStatement(
            "SELECT DATE_FORMAT(vp.data_visualitzacio, '%d/%m/%Y %H:%i') AS data, "
            "p.titol_Pelicula, p.descripcio, p.pegis, vp.num_visualitzacions "
            "FROM inep21.visualitzacio_Pelicula vp "
            "JOIN inep21.Pelicula p ON vp.titol_Pelicula = p.titol_Pelicula "
            "WHERE vp.sobrenom_usuari = ? "
            "ORDER BY vp.data_visualitzacio DESC;"
        );
        pstmt->setString(1, sobrenom);

        sql::ResultSet *res = pstmt->executeQuery();

        while (res->next())
        {
            // Omplim els vectors amb les dades obtingudes
            this->data.push_back(res->getString("data"));
            this->titol.push_back(res->getString("titol_Pelicula"));
            this->descripcio.push_back(res->getString("descripcio"));
            this->pegi.push_back(res->getInt("pegis"));
            this->numVisualitzacions.push_back(res->getInt("num_visualitzacions"));
        }

        close_connection(conn, pstmt, res);
    }
    catch (sql::SQLException &e)
    {
        cerr << "SQL Error: " << e.what() << endl;
    }
}

CercadoraVisualitzaPeli::~CercadoraVisualitzaPeli() {}

// Implementació dels mètodes per obtenir les dades
vector<string> CercadoraVisualitzaPeli::obteData()
{
    return this->data;
}

vector<string> CercadoraVisualitzaPeli::obteTitol()
{
    return this->titol;
}

vector<string> CercadoraVisualitzaPeli::obteDescripcio()
{
    return this->descripcio;
}

vector<int> CercadoraVisualitzaPeli::obtePegi()
{
    return this->pegi;
}

vector<int> CercadoraVisualitzaPeli::obteNumVisualitzacions()
{
    return this->numVisualitzacions;
}

CercadoraVisualitzaPeli& CercadoraVisualitzaPeli::operator=(const CercadoraVisualitzaPeli &other)
{
    if (this != &other)
    {
        this->data = other.data;
        this->titol = other.titol;
        this->descripcio = other.descripcio;
        this->pegi = other.pegi;
        this->numVisualitzacions = other.numVisualitzacions;
    }
    return *this;
}

int CercadoraVisualitzaPeli::cercaVisualitzacions(string sobrenom)
{
    int result = 0;
    try
    {
        sql::Connection *conn = open_connection();

        sql::PreparedStatement *pstmt = conn->prepareStatement("SELECT COUNT(titol_pelicula) FROM inep21.visualitzacio_pelicula WHERE sobrenom_usuari = ?");
        pstmt->setString(1, sobrenom);

        sql::ResultSet *res = pstmt->executeQuery();

        if (res->next())
            result = res->getInt(1);
        close_connection(conn, pstmt, res);
    }
    catch (sql::SQLException &e)
    {
        cerr << "SQL Error: " << e.what() << endl;
    }
    return result;
}