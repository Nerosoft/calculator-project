class ReadWriteFile {
public:
	virtual std::vector<std::vector<Input>> read_result(Json m_json) = 0;
	virtual Table read_table(Json m_json) = 0;
	virtual Colors read_colors(Json m_json) = 0;
	virtual Main read_main(Json m_json) = 0;
	virtual Dialog read_dialog(Json m_json) = 0;
	virtual Help read_Help(Json m_json) = 0;
	virtual AddSearchEdit read_add_search_edit(std::string name, Json m_json) = 0;
	virtual Confirm read_confirm(Json m_json)	= 0;
	virtual Delete read_delete(Json m_json) = 0;
	virtual void write_result(std::vector<std::vector<Input>> result, Json m_json) = 0;
	virtual Json read_setting()	= 0;
};
