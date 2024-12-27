#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <iostream>
#include <fstream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

// Function declarations
sql::Connection* open_connection();
void close_connection(sql::Connection *conn, sql::Statement* stmt, sql::ResultSet* res);

sql::ResultSet* fetchMovieDetails(const std::string& title);
void recordMovieVisualization(const std::string& userNickname, const std::string& title);

sql::ResultSet* fetchSeasons(const std::string& seriesTitle);
sql::ResultSet* fetchEpisodes(const std::string& seriesTitle, int seasonNumber);
void recordEpisodeVisualization(const std::string& userNickname, const std::string& seriesTitle, int seasonNumber, int episodeNumber);


#endif
