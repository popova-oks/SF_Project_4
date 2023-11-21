#pragma once
#include "IObserver.h"
#include "../headers/jsonHandler.h"
#include <map>


template <typename T> class Messages {
  public:
    Messages();
    ~Messages(){};
    //void set_message(IObserver* sender, const T& message);
    nlohmann::json create_message(const std::string &sender, const std::string &receiver, T message);
    //void save_message(const std::string& sender, const std::string& receiver, const T & message);
    void save_message(const nlohmann::json &json);
    void send_message(const nlohmann::json &json);
    void get_messages();
    void update_JSON(const char* message);
    const std::string& get_pathJSON () {return pathJSON_;}
  private:
    //std::multimap<IObserver*, T> msg_{};
    std::string pathJSON_;
};