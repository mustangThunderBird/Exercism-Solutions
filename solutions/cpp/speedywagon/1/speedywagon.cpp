#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:
bool connection_check(pillar_men_sensor* sensor){
    return sensor != nullptr;
}

int activity_counter(pillar_men_sensor* arr, int size){
    int count = 0;
    for(int i = 0; i < size; ++i){
        count += (arr + i)->activity;
    }
    return count;
}

bool alarm_control(pillar_men_sensor* db){
    if(db == nullptr){
        return false;
    }
    return db->activity > 0;
}

bool uv_alarm(pillar_men_sensor* pms){
    if(pms == nullptr){
        return false;
    }
    int uv_idx = uv_light_heuristic(&pms->data);
    return uv_idx > pms->activity;
}

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

}  // namespace speedywagon
