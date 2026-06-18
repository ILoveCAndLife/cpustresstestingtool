#include <boost/asio.hpp>
#include <iostream>
#include <string>


int main() {
   std::string agree;
   std::string decision;

   int StressAmount;

   boost::asio::io_context io_context;





   std::cout << "___     ___      _________\n";
   std::cout << "| |     | |      |__   __|\n";
   std::cout << "| |_____| |         | |\n";
   std::cout << "|  _____  |         | |\n";
   std::cout << "|  |   |  |         | |\n";
   std::cout << "|  |   |  |      ___| |___\n";
   std::cout << "|__|   |__|      |_______|\n";
   std::cout << " ";
   std::cout << "welcome to my stress testing tool,\n";
   std::cout << "HI.\n";
   std::cout << "please type y if you accept that this loops back to 127.0.0.1 as a stress testing tool.\n";
   std::cout << "type n if you disagree, and don't want to use this program.\n";
   std::cout << "by using this, you agree that if you edit this source code you have full liability of your actions.\n";
   std::cin >> agree;

   if (agree == "y") {
      std::cout << "great. now, please enter if you would like to be tested by UDP or TCP.\n";
      std::cout << "type udp for your decision. tcp is coming in the next patch.\n";
      std::cin >> decision;

      if (decision == "udp") {
         boost::asio::ip::udp::socket socket{io_context};
         socket.open(boost::asio::ip::udp::v4());
         std::cout << "great. now please enter the amount of stress you would like.\n";
         std::cin >> StressAmount;

         for (; StressAmount > 0; --StressAmount) {
            std::cout << "get ready to be annihilated lol\n";
            socket.send_to(
               boost::asio::buffer("RIP"),
               boost::asio::ip::udp::endpoint{
                  boost::asio::ip::make_address("127.0.0.1"), 3303});
         }
         return 0;

      }

   } else if (agree == "n") {
      std::cout << "alright.\n";
      return 0;
   } else {
      std::cout << "invalid answer.\n";
      return 0;
   }
}