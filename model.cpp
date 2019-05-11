#include "model.h"

Model::Model(const std::string &config)
{
    _alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    _config = config;
    configure(config);

}

void Model::configure(std::string info)
{

}

std::string Model::encrypt(std::string &message)
{
    return "*****";
}
