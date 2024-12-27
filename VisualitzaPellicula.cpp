#include "VisualitzaPellicula.h"

void VisualitzaPellicula::visualitza(const std::string& userNickname, const std::string& movieTitle) {
    DBConnection db;
    sql::ResultSet* movieDetails = db.fetchMovieDetails(movieTitle);

    if (!movieDetails || !movieDetails->next()) {
        std::cout << "La pel·lícula no existeix.\n";
        return;
    }

    int ageRating = std::stoi(movieDetails->getString("qualificacio_edat"));
    int duration = movieDetails->getInt("duracio");
    std::string description = movieDetails->getString("descripcio");
    std::string releaseDate = movieDetails->getString("data_estrena");

    std::cout << "Títol: " << movieTitle << "\n"
              << "Descripció: " << description << "\n"
              << "Qualificació per edat: " << ageRating << "+\n"
              << "Duració: " << duration << " minuts\n"
              << "Data d'estrena: " << releaseDate << "\n";

    std::cout << "Vols visualitzar aquesta pel·lícula? (S/N): ";
    char response;
    std::cin >> response;

    if (toupper(response) == 'S') {
        db.recordMovieVisualization(userNickname, movieTitle);
        std::cout << "La pel·lícula ha estat registrada com visualitzada.\n";
    } else {
        std::cout << "Visualització cancel·lada.\n";
    }
}
