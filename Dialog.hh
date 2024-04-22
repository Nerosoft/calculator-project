#pragma once
class Dialog {
public:
    std::string m_menu_title_add;
    std::string m_input_menu_add;
    std::string m_print_menu_statement_add;
    std::string m_print_error_menu_statement_add;
    std::string m_print_successfully_menu_statement_add;
    std::string m_print_successfully_menu_statement_main_screen;
    std::string m_print_successfully_menu_statement_add_screen;
    std::string m_print_successfully_menu_statement_search_screen;
    std::string m_print_successfully_menu_statement_confirm_screen;
    std::string m_print_successfully_menu_statement_edit_screen;
    std::string m_print_successfully_menu_statement_delete_screen;
    std::string m_print_screen_add;
    std::string m_menu_title_search;
    std::string m_input_menu_search;
    std::string m_print_menu_statement_search;
    std::string m_print_error_menu_statement_search;
    std::string m_print_successfully_menu_statement_search;
    std::string m_print_screen_search;
    std::string m_menu_title_edit;
    std::string m_input_menu_edit;
    std::string m_print_menu_statement_edit;
    std::string m_print_error_menu_statement_edit;
    std::string m_print_successfully_menu_statement_edit;
    std::string m_print_screen_edit;
    std::string m_menu_title_main;
    std::string m_input_menu_main;
    std::string m_print_menu_statement_main;
    std::string m_print_error_menu_statement_main;
    std::string m_print_successfully_menu_statement_main;
    std::string m_print_screen_main;
    std::string m_menu_title_confirm;
    std::string m_input_menu_confirm;
    std::string m_print_menu_statement_confirm;
    std::string m_print_error_menu_statement_confirm;
    std::string m_print_successfully_menu_statement_confirm;
    std::string m_print_screen_confirm;
    std::string m_menu_title_delete;
    std::string m_input_menu_delete;
    std::string m_print_menu_statement_delete;
    std::string m_print_error_menu_statement_delete;
    std::string m_print_successfully_menu_statement_delete;
    std::string m_print_screen_delete;
    std::string m_print_screen_exit;
    Dialog() = default;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Dialog,
        m_menu_title_add,
        m_input_menu_add,
        m_print_menu_statement_add,
        m_print_error_menu_statement_add,
        m_print_successfully_menu_statement_add,
        m_print_successfully_menu_statement_main_screen,
        m_print_successfully_menu_statement_add_screen,
        m_print_successfully_menu_statement_search_screen,
        m_print_successfully_menu_statement_confirm_screen,
        m_print_successfully_menu_statement_edit_screen,
        m_print_successfully_menu_statement_delete_screen,
        m_print_screen_add,
        m_menu_title_search,
        m_input_menu_search,
        m_print_menu_statement_search,
        m_print_error_menu_statement_search,
        m_print_successfully_menu_statement_search,
        m_print_screen_search,
        m_menu_title_edit,
        m_input_menu_edit,
        m_print_menu_statement_edit,
        m_print_error_menu_statement_edit,
        m_print_successfully_menu_statement_edit,
        m_print_screen_edit,
        m_menu_title_main,
        m_input_menu_main,
        m_print_menu_statement_main,
        m_print_error_menu_statement_main,
        m_print_successfully_menu_statement_main,
        m_print_screen_main,
        m_menu_title_confirm,
        m_input_menu_confirm,
        m_print_menu_statement_confirm,
        m_print_error_menu_statement_confirm,
        m_print_successfully_menu_statement_confirm,
        m_print_screen_confirm,
        m_menu_title_delete,
        m_input_menu_delete,
        m_print_menu_statement_delete,
        m_print_error_menu_statement_delete,
        m_print_successfully_menu_statement_delete,
        m_print_screen_delete,
        m_print_screen_exit
    )

};
