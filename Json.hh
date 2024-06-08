#pragma once
class Json {
public:
    int m_index;
    std::string m_application;
    std::string m_name;
    std::string m_language;
    Json() = default;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Json, m_index, m_application, m_name, m_language)
};

