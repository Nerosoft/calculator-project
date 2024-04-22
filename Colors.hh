#pragma once
class Colors {
public:
    std::string m_color_help;
    std::string m_color_result_title;
    std::string m_color_menu_statement;
    std::string m_color_error_menu_statement;
    std::string m_color_successfully_menu_statement;
    std::string m_color_statement_confirm;
    std::string m_color_error_statement_confirm;
    std::string m_color_successfully_statement_confirm;
    std::string m_color_successfully_statement_message_confirm;
    std::string m_color_number;
    std::string m_color_error_number;
    std::string m_color_operator;
    std::string m_color_error_operator;
    std::string m_color_clear;
    std::string m_color_select;
    std::string m_color_result_table;
    std::string m_color_sugges_table;
    std::string m_color_sugges_title;
    std::string m_color_data_table;
    std::string m_color_data_title;

    std::string m_color_menu_title;
    std::string m_color_menu_table;

    std::string m_color_error_message_user;

    Colors() = default;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Colors,
        m_color_help,
        m_color_result_title,
        m_color_menu_statement,
        m_color_error_menu_statement,
        m_color_successfully_menu_statement,
        m_color_statement_confirm,
        m_color_error_statement_confirm,
        m_color_successfully_statement_confirm,
        m_color_successfully_statement_message_confirm,
        m_color_number,
        m_color_error_number,
        m_color_operator,
        m_color_error_operator,
        m_color_clear,
        m_color_select,
        m_color_result_table,
        m_color_sugges_table,
        m_color_sugges_title,
        m_color_data_table,
        m_color_data_title,
        m_color_menu_title,
        m_color_menu_table,
        m_color_error_message_user
    )
};
