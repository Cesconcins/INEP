#include "CercadoraVisualitzaSerie.h"

CercadoraVisualitzaSerie::CercadoraVisualitzaSerie() {}

CercadoraVisualitzaSerie::CercadoraVisualitzaSerie(string sobrenom)
{
    try
    {
        sql::Connection *conn = open_connection();

        sql::PreparedStatement *pstmt = conn->prepareStatement(
            "SELECT DATE_FORMAT(vc.data_visualitzacio, '%d/%m/%Y %H:%i') AS data, "
            "s.titol_serie, vc.numero_temporada, vc.numero AS capitol, s.pegis, vc.num_visualitzacions "
            "FROM inep21.visualitzacio_capitol vc "
            "JOIN inep21.serie s ON vc.titol_serie = s.titol_serie "
            "WHERE vc.sobrenom_usuari = ? "
            "ORDER BY vc.data_visualitzacio DESC;"
        );
        pstmt->setString(1, sobrenom);

        sql::ResultSet *res = pstmt->executeQuery();

        while (res->next())
        {
            // Omplim els vectors amb les dades obtingudes
            this->data.push_back(res->getString("data"));
            this->titol.push_back(res->getString("titol_serie"));
            this->numTemporada.push_back(res->getInt("numero_temporada"));
            this->numCapitol.push_back(res->getInt("capitol"));
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

CercadoraVisualitzaSerie::~CercadoraVisualitzaSerie() {}

CercadoraVisualitzaSerie& CercadoraVisualitzaSerie::operator=(const CercadoraVisualitzaSerie &other)
{
    if (this != &other)
    {
        this->data = other.data;
        this->titol = other.titol;
        this->numTemporada = other.numTemporada;
        this->numCapitol = other.numCapitol;
        this->pegi = other.pegi;
        this->numVisualitzacions = other.numVisualitzacions;
    }
    return *this;
}

// Implementació dels mètodes per obtenir les dades
vector<string> CercadoraVisualitzaSerie::obteData()
{
    return this->data;
}

vector<string> CercadoraVisualitzaSerie::obteTitol()
{
    return this->titol;
}

vector<int> CercadoraVisualitzaSerie::obteNumTemporada()
{
    return this->numTemporada;
}

vector<int> CercadoraVisualitzaSerie::obteNumCapitol()
{
    return this->numCapitol;
}

vector<int> CercadoraVisualitzaSerie::obtePegi()
{
    return this->pegi;
}

vector<int> CercadoraVisualitzaSerie::obteNumVisualitzacions()
{
    return this->numVisualitzacions;
}

int CercadoraVisualitzaSerie::cercaVisualitzacions(string sobrenom)
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
        cerr << "SQL Error: " << e.what() << endl;
    }
    return result;
}