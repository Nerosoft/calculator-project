#pragma once
class ReadFile {
protected:
	virtual void read_help() = 0;
	virtual void read_dialog() = 0;
	virtual void read_add() = 0;
	virtual void read_search() = 0;
	virtual void read_edit() = 0;
	virtual void read_delete() = 0;
	virtual void read_confirm() = 0;
	virtual void read_main() = 0;
	virtual void read_table() = 0;
	virtual void read_colors() = 0;
	virtual void read_setting() = 0;
	virtual void read_result() = 0;
};