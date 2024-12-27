#include "VisualitzaCapitol.h"

void VisualitzaCapitol::visualitza(const std::string& userNickname, const std::string& seriesTitle) {
    DBConnection db;
    sql::ResultSet* seasons = db.fetchSeasons(seriesTitle);

    if (!seasons || !seasons->next()) {
        std::cout << "La sèrie no existeix o no té temporades.\n";
        return;
    }

    std::cout << "Temporades disponibles:\n";
    do {
        std::cout << "Temporada " << seasons->getInt("numero") << "\n";
    } while (seasons->next());

    int selectedSeason;
    std::cout << "Introdueix el número de temporada: ";
    std::cin >> selectedSeason;

    sql::ResultSet* episodes = db.fetchEpisodes(seriesTitle, selectedSeason);
    if (!episodes || !episodes->next()) {
        std::cout << "No hi ha capítols disponibles per aquesta temporada.\n";
        return;
    }

    std::cout << "Capítols disponibles:\n";
    do {
        std::cout << "Capítol " << episodes->getInt("numero") << ": " << episodes->getString("titol")
                  << " (Estrena: " << episodes->getString("data_estrena") << ")\n";
    } while (episodes->next());

    int selectedEpisode;
    std::cout << "Introdueix el número del capítol: ";
    std::cin >> selectedEpisode;

    char response;
    std::cout << "Vols visualitzar aquest capítol? (S/N): ";
    std::cin >> response;

    if (toupper(response) == 'S') {
        db.recordEpisodeVisualization(userNickname, seriesTitle, selectedSeason, selectedEpisode);
        std::cout << "El capítol ha estat registrat com visualitzat.\n";
    } else {
        std::cout << "Visualització cancel·lada.\n";
    }
}
