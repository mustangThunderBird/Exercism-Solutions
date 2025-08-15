#include "power_of_troy.h"
#include <utility>


namespace troy {
    void give_new_artifact(human& h, std::string new_artifact){
        if (!h.possession) {
            h.possession = std::make_unique<artifact>(std::move(new_artifact));
        } else {
            h.possession->name = std::move(new_artifact);
        }
    }
    void exchange_artifacts(std::unique_ptr<artifact>& a1, std::unique_ptr<artifact>& a2){
        std::swap(a1,a2);
    }
    void manifest_power(human& h, std::string s){
        if(h.own_power == nullptr){
            h.own_power = std::make_shared<power>("");
        }
        h.own_power->effect = std::move(s);
    }
    void use_power(human& caster, human& target){
        if(target.influenced_by == nullptr){
            target.influenced_by = std::make_shared<power>("");
        }
        target.influenced_by = caster.own_power;
    }
    int power_intensity(const human& h){
        if (h.own_power) {
            return static_cast<int>(h.own_power.use_count());
        }
        if (h.influenced_by) {
            return static_cast<int>(h.influenced_by.use_count());
        }
        return 0;
    }
}  // namespace troy
