#pragma once
class Main {
public:
    std::string m_input_key_add;
    std::string m_input_key_search;
    std::string m_print_successfully_statement_confirm_add;
    std::string m_print_successfully_statement_confirm_search;

    std::string m_print_message_user;
    std::string m_print_error_message_user;
    std::string m_print_successfully_statement_message_confirm;
    Main() = default;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Main,
        m_input_key_add,
        m_input_key_search,
        m_print_successfully_statement_confirm_add,
        m_print_successfully_statement_confirm_search,

        m_print_message_user,
        m_print_error_message_user,
        m_print_successfully_statement_message_confirm
    )
};
