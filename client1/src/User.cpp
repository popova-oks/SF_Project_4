#include "../headers/User.h"
#include "../headers/Chat.h"
//#include "../headers/sha1.h"
#include <iostream>

User::User(Chat* chat) : chat_(chat) { chat_->set_User(this); }

User* User::log_in(Chat* chat) {
    if(is_autorization_) {
        std::cout << "\nYou are login!\n";
    } else {
        chat->attach(this);
    }
    return this;
}

/*/
void User::create_message() {

    char event;
    while(true) {
        std::cout << "\nEnter an action: s - send to all users, c - chose some user, q - quit: ";
        std::cin >> event;
        if(event == 'q') {
            return;
        } else if(event == 's' || event == 'c') {
            chat_->notify(this, event);
        } else {
            std::cout << "\nTry agan!\n";
        }
    }
}
*/

void User::exchange_messages() {
    char event;
    while(true) {
        // std::cout << "\nEnter an action: s - send to all users, c - send to chosed user, r -
        // receive a message"
        std::cout << "\nEnter an action: s - send a message to any user, q - quit: ";
        std::cin >> event;
        if(event == 'q') {            
            return;
        } else if(event == 's') {
            chat_->notify(this, event);
        } else {
            std::cout << "\nTry agan!\n";
        }
    }
}

/*
void User::update(IObserver* sender, const std::string& message) {
    messages_.insert({sender, message});
}
*/

void User::display_Messages() {
    /*
    if(messages_.empty()) {
        std::cout << "No messages!\n";
    }
    for(std::pair<const IObserver*, const std::string&> msg : messages_) {
        std::cout << "The message received from user: " << msg.first->get_login() << "\n";
        std::cout << "The message: " << msg.second << "\n\n";
    }
    */
    chat_->display_Messages_fromJSON(this);
}

void User::leave_chat(Chat* chat) {
    chat->detach(this);
    set_notAutorization();
    std::cout << "\nYou are detached from the chat!\n";
}

int User::static_counter = 0;