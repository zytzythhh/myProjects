package com.java1234.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

import com.java1234.model.Reader;

/**
 * 读者dao类
 */
public class ReaderDao {
	/**
	 * 登录验证
	 * @param con
	 * @param reader
	 * @return
	 * @throws Exception
	 */
	public Reader login(Connection con,Reader reader)throws Exception{
		Reader resultReader=null;
		String sql="select * from t_reader where reader_name=? and reader_password=?";
		PreparedStatement pstmt=con.prepareStatement(sql);
		pstmt.setString(1, reader.getReader_name());
		pstmt.setString(2, reader.getReader_password());
		ResultSet rs=pstmt.executeQuery();
		if(rs.next()) {
			resultReader=new Reader();
			resultReader.setId(rs.getInt("id"));
			resultReader.setReader_name(rs.getString("reader_name"));
			resultReader.setReader_password(rs.getString("reader_password"));
		}
		return resultReader;
	}
	/**
	 * 读者身份添加（注册）
	 * @param con
	 * @param bookType
	 * @return
	 * @throws Exception
	 */
	public int add(Connection con,Reader reader)throws Exception{
		String sql="insert into t_reader values(null,?,?)";
		PreparedStatement pstmt=con.prepareStatement(sql);
		pstmt.setString(1, reader.getReader_name());
		pstmt.setString(2, reader.getReader_password());
		
		return pstmt.executeUpdate();
	}
}
