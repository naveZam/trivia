#include "LoggedUser.h"

LoggedUser::LoggedUser(std::string username)
{
    this->username = username;
}

std::string LoggedUser::getUsername()
{
    return username;
}

bool LoggedUser::operator<(const LoggedUser& other) const
{
    return false;
}
