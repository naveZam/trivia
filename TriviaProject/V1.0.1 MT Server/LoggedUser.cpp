#include "LoggedUser.h"

LoggedUser::LoggedUser(std::string username)
{
    this->username = username;
}

std::string LoggedUser::getUsername()
{
    return username;
}
