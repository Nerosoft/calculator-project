#pragma once
class Json {
public:
    int m_index;
    std::string m_application;
    std::string m_name;
    Json() = default;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Json, m_index, m_application, m_name)
};

