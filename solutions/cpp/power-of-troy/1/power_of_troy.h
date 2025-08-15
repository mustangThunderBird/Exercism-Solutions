#pragma once

#include <string>
#include <memory>

namespace troy {

struct artifact {
    // constructors needed (until C++20)
    artifact(std::string name) : name(name) {}
    std::string name;
};

struct power {
    // constructors needed (until C++20)
    power(std::string effect) : effect(effect) {}
    std::string effect;
};

struct human {
    std::unique_ptr<artifact> possession;
    human() : possession(){}
    std::shared_ptr<power> own_power;
    std::shared_ptr<power> influenced_by;
};

void give_new_artifact(human& h, std::string new_artifact);
void exchange_artifacts(std::unique_ptr<artifact>& a1, std::unique_ptr<artifact>& a2);
void manifest_power(human& h, std::string s);
void use_power(human& caster, human& target);
int power_intensity(const human& h);
}  // namespace troy
