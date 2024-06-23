#pragma once
class Colors {
public:
    std::string m_color_app_menu;
    std::string m_color_address_menu;
    std::string m_color_app_exit_menu;
    std::string m_color_app_main_menu;
    std::string m_color_app_add_menu;
    std::string m_color_app_search;
    std::string m_color_app_confirm_menu;
    std::string m_color_app_edit_menu;
    std::string m_color_app_delete_menu;

    std::string m_color_value_result;
    std::string m_color_operator_result;
    std::string m_color_total_result;
    std::string m_color_address_result;

    std::string m_color_value_sugges;
    std::string m_color_operator_sugges;
    std::string m_color_total_sugges;
    std::string m_color_address_sugges;

    std::string m_color_value_data;
    std::string m_color_operator_data;
    std::string m_color_total_data;
    std::string m_color_address_data;

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


    std::string m_color_main;
    std::string m_color_confirm;

    std::string m_color_confirm_table;
    std::string m_color_confirm_title;
    std::string m_color_value_confirm;
    std::string m_color_operator_confirm;
    std::string m_color_total_confirm;
    std::string m_color_address_confirm;


    std::string m_color_delete_table;
    std::string m_color_delete_title;
    std::string m_color_value_delete;
    std::string m_color_operator_delete;
    std::string m_color_total_delete;
    std::string m_color_address_delete;


    std::string m_color_display_table;
    std::string m_color_display_title;
    std::string m_color_value_display;
    std::string m_color_operator_display;
    std::string m_color_total_display;
    std::string m_color_address_display;

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
        m_color_value_result,
        m_color_operator_result,
        m_color_total_result,
        m_color_address_result,
        m_color_value_sugges,
        m_color_operator_sugges,
        m_color_total_sugges,
        m_color_address_sugges,
        m_color_value_data,
        m_color_operator_data,
        m_color_total_data,
        m_color_address_data,
        m_color_app_menu,
        m_color_address_menu,
        m_color_app_exit_menu,
        m_color_app_main_menu,
        m_color_app_add_menu,
        m_color_app_search,
        m_color_app_confirm_menu,
        m_color_app_edit_menu,
        m_color_app_delete_menu,
        m_color_main,

        m_color_confirm,
        m_color_confirm_table,
        m_color_confirm_title,
        m_color_value_confirm,
        m_color_operator_confirm,
        m_color_total_confirm,
        m_color_address_confirm,

        m_color_delete_table,
        m_color_delete_title,
        m_color_value_delete,
        m_color_operator_delete,
        m_color_total_delete,
        m_color_address_delete,

        m_color_display_table,
        m_color_display_title,
        m_color_value_display,
        m_color_operator_display,
        m_color_total_display,
        m_color_address_display
    )
};
