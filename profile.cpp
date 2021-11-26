#include <iostream>
#include "profile.h"

Profile::Profile(std::string usrn, std::string dspn){
  username = usrn;
  displayname = dspn;
}

Profile::Profile(){
  username = "";
  displayname = "";
}

std::string Profile::getUsername(){
  return username;
}

std::string Profile::getFullName(){
  return displayname + " (@" + username + ")";
}

void Profile::setDisplayName(std::string dspn){
  displayname = dspn;
}

Network::Network(){
  numUsers = 0;
  for(int i = 0; i < MAX_USERS; i++){
    for(int j = 0; j < MAX_USERS; j++){
      following[i][j] = false;
    }
  }
}

int Network::findID(std::string usrn){
  for (int i = 0; i < MAX_USERS; i++){
    if(profiles[i].getUsername() == usrn){
      return i;
    }
  }
  return -1;
}

bool Network::addUser(std::string usrn, std::string dspn){
  if(numUsers < 20){
    Profile user(usrn, dspn);
    //checking if username or displayname already exists
    if (findID(usrn) == -1){
      profiles[numUsers] = user;
      numUsers+=1;
      return true;
    } else {
      return false;
    }
  } else {
    return false;
  }
}

bool Network::follow(std::string usrn1, std::string usrn2){
  int one = findID(usrn1);
  int two = findID(usrn2);

  if (one == -1 || two == -1){
    return false;
  } else {
    following[one][two] = true;
    return true;
  }
}

void Network::printDot(){
  for (int i = 0; i < numUsers; i++){
    std::cout << "\"@" + profiles[i].getUsername() + "\"" << std::endl;
  }

  std::cout << std::endl;
  for (int i = 0; i < numUsers; i++){
    for (int j = 0; j < numUsers; j++){
      if (following[i][j]){
        std::cout << profiles[i].getUsername() + " -> " + profiles[j].getUsername() << std::endl;
      }
    }
  }
}
