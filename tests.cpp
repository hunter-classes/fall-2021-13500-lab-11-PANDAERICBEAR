#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

TEST_CASE("Task A"){
  Profile user("Eric Li", "DUMBPANDABEAR");
  CHECK(user.getUsername() == "Eric Li");
  CHECK(user.getFullName() == "DUMBPANDABEAR (@Eric Li)");

  Profile p1("marco", "Marco");
  CHECK(p1.getUsername() == "marco");
  CHECK(p1.getFullName() == "Marco (@marco)");
  p1.setDisplayName("Marco Rossi");
  CHECK(p1.getUsername() == "marco");
  CHECK(p1.getFullName() == "Marco Rossi (@marco)");

  Profile p2("tarma1", "Tarma Roving");
  CHECK(p2.getUsername() == "tarma1");
  CHECK(p2.getFullName() == "Tarma Roving (@tarma1)");
}

TEST_CASE("Task B"){
  Network net;
  CHECK(net.addUser("mario", "Mario") == 1); // true (1)
  CHECK(net.addUser("luigi", "Luigi") == 1);

  CHECK(net.addUser("mario", "Mario2") == 0); // false (0)
  CHECK(net.addUser("luigi", "Apple1") == 0);
}

TEST_CASE("Task C"){
  Network nw;
  // add three users
  nw.addUser("mario", "Mario");
  nw.addUser("luigi", "Luigi");
  nw.addUser("yoshi", "Yoshi");

  // make them follow each other
  CHECK(nw.follow("mario", "luigi"));
  CHECK(nw.follow("mario", "yoshi"));
  CHECK(nw.follow("luigi", "mario"));
  CHECK(nw.follow("luigi", "yoshi"));
  CHECK(nw.follow("yoshi", "mario"));
  CHECK(nw.follow("yoshi", "luigi"));
  CHECK(!nw.follow("DUMBPANDABEAR", "mario"));
  CHECK(!nw.follow("mario", "wario"));

  // add a user who does not follow others
  nw.addUser("wario", "Wario");
  CHECK(nw.follow("wario", "mario"));

  // add clone users who follow @mario
  for(int i = 2; i < 6; i++) {
      std::string usrn = "mario" + std::to_string(i);
      std::string dspn = "Mario " + std::to_string(i);
      nw.addUser(usrn, dspn);
      CHECK(nw.follow(usrn, "mario"));
  }
}
