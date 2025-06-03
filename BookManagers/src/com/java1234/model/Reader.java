package com.java1234.model;
/**
 * 读者实体
 */
public class Reader {
	private int id;//编号
	private String reader_name;//读者姓名
	private String reader_password;//读者密码
	
	public Reader() {
		super();
		// TODO Auto-generated constructor stub
		
	}
	
	public Reader(String reader_name, String reader_password) {
		super();
		this.reader_name = reader_name;
		this.reader_password = reader_password;
	}

	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getReader_name() {
		return reader_name;
	}
	public void setReader_name(String reader_name) {
		this.reader_name = reader_name;
	}
	public String getReader_password() {
		return reader_password;
	}
	public void setReader_password(String reader_password) {
		this.reader_password = reader_password;
	}
	
	
}
