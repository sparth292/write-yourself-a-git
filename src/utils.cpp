#include "utils.h"
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

std::string get_timestamp_with_timezone(){
    std::time_t now =  std::time(nullptr);
    std::tm local_tm = *std::localtime(&now);
    std::tm utc_tm = *std::gmtime(&now);

    int offset_seconds =
    (local_tm.tm_hour - utc_tm.tm_hour) * 3600 + 
    (local_tm.tm_min - utc_tm.tm_min) * 60;

    if(local_tm.tm_mday != utc_tm.tm_mday){
        
    }
    

}