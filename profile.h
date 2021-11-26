#include <iostream>

class Profile {
private:
    std::string username;
    std::string displayname;
public:
    // Profile constructor for a user (initializing
    // private variables username=usrn, displayname=dspn)
    Profile(std::string usrn, std::string dspn);
    // Default Profile constructor (username="", displayname="")
    Profile();
    // Return username
    std::string getUsername();
    // Return name in the format: "displayname (@username)"
    std::string getFullName();
    // Change display name
    void setDisplayName(std::string dspn);
};

class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile
  bool following[MAX_USERS][MAX_USERS];  // friendship matrix:
    // following[id1][id2] == true when id1 is following id2


  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (std::string usrn);
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network();
  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool addUser(std::string usrn, std::string dspn);
  // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
  // return true if success (if both usernames exist), otherwise return false
  bool follow(std::string usrn1, std::string usrn2);
  // Print Dot file (graphical representation of the network)
  void printDot();
};
