#pragma once
class Confirm {
public:
    std::string m_input_key_edit;
    std::string m_input_key_delete;
    std::string m_print_successfully_statement_confirm_edit;
    std::string m_print_successfully_statement_confirm_delete;
    std::string m_print_message_user;
    std::string m_print_error_message_user;
    Confirm() = default;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Confirm,
        m_input_key_edit,
        m_input_key_delete,
        m_print_successfully_statement_confirm_edit,
        m_print_successfully_statement_confirm_delete,
        m_print_message_user,
        m_print_error_message_user
    )
};
