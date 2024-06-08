#pragma once
class Delete {
public:
    std::string m_input_y;
    std::string m_input_n;
    std::string m_print_statement_confirm;
    std::string m_print_error_message_user;
    std::string m_print_successfully_statement_message_confirm;
    std::string m_print_successfully_statement_confirm_delete;
    Delete() = default;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Delete,
        m_input_y,
        m_input_n,
        m_print_statement_confirm,
        m_print_error_message_user,
        m_print_successfully_statement_message_confirm,
        m_print_successfully_statement_confirm_delete
    )
};
