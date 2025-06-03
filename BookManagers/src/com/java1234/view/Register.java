package com.java1234.view;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;

import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import javax.swing.LayoutStyle.ComponentPlacement;
import javax.swing.border.EmptyBorder;

import com.java1234.dao.UserDao;
import com.java1234.model.User;
import com.java1234.util.DbUtil;
import com.java1234.util.StringUtil;

public class Register extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JPasswordField AdmPasswordtxt;
	private JPasswordField AdmPasswordtxtRE;
	private JTextField AdmNametxt;
	
	private DbUtil dbUtil=new DbUtil();
	private UserDao userDao=new UserDao();

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			@Override
			public void run() {
				try {
					Register frame = new Register();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public Register() {
		setResizable(false);
		setTitle("注册——管理员注册");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 445, 327);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		
		JLabel lblNewLabel = new JLabel("欢迎来到管理员注册");
		lblNewLabel.setFont(new Font("宋体", Font.BOLD, 20));
		lblNewLabel.setBackground(new Color(255, 255, 128));
		
		JLabel lblNewLabel_1 = new JLabel("账    号：");
		lblNewLabel_1.setFont(new Font("宋体", Font.BOLD, 15));
		
		JLabel lblNewLabel_2 = new JLabel("密    码：");
		lblNewLabel_2.setFont(new Font("宋体", Font.BOLD, 15));
		
		JLabel lblNewLabel_3 = new JLabel("确认密码：");
		lblNewLabel_3.setFont(new Font("宋体", Font.BOLD, 15));
		
		AdmPasswordtxt = new JPasswordField();
		
		AdmPasswordtxtRE = new JPasswordField();
		
		JButton btnNewButton = new JButton("注    册");
		btnNewButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				RegisterActionPerformed(e);
			}
		});
		
		JButton btnNewButton_1 = new JButton("重    置");
		btnNewButton_1.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				ResetValueActionPerformed(e);
			}
		});
		
		AdmNametxt = new JTextField();
		AdmNametxt.setColumns(10);
		
		JLabel lblNewLabel_4 = new JLabel("（20个字符以内的数字、字母组合）");
		
		JLabel lblNewLabel_5 = new JLabel("（20个字符以内的数字、字母组合）");
		
		JLabel lblNewLabel_5_1 = new JLabel("（20个字符以内的数字、字母组合）");
		
		JButton btnNewButton_2 = new JButton("点此登录");
		btnNewButton_2.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				LogInActionPerformed(e);
			}
		});
		
		JButton btnNewButton_3 = new JButton("返回");
		btnNewButton_3.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				BackActionPerformed(e);
			}
		});
		GroupLayout gl_contentPane = new GroupLayout(contentPane);
		gl_contentPane.setHorizontalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
						.addGroup(gl_contentPane.createSequentialGroup()
							.addContainerGap(63, Short.MAX_VALUE)
							.addGroup(gl_contentPane.createParallelGroup(Alignment.TRAILING, false)
								.addGroup(gl_contentPane.createSequentialGroup()
									.addComponent(btnNewButton, GroupLayout.PREFERRED_SIZE, 97, GroupLayout.PREFERRED_SIZE)
									.addGap(17))
								.addGroup(gl_contentPane.createSequentialGroup()
									.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
										.addComponent(lblNewLabel_2)
										.addComponent(lblNewLabel_3)
										.addComponent(lblNewLabel_1))
									.addGap(44))))
						.addGroup(gl_contentPane.createSequentialGroup()
							.addGap(42)
							.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
								.addComponent(btnNewButton_3, GroupLayout.PREFERRED_SIZE, 97, GroupLayout.PREFERRED_SIZE)
								.addComponent(btnNewButton_2, GroupLayout.PREFERRED_SIZE, 97, GroupLayout.PREFERRED_SIZE))
							.addGap(47)))
					.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
						.addGroup(gl_contentPane.createSequentialGroup()
							.addPreferredGap(ComponentPlacement.RELATED)
							.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
								.addComponent(AdmPasswordtxtRE, GroupLayout.PREFERRED_SIZE, 190, GroupLayout.PREFERRED_SIZE)
								.addComponent(AdmPasswordtxt, GroupLayout.PREFERRED_SIZE, 189, GroupLayout.PREFERRED_SIZE)
								.addComponent(AdmNametxt, GroupLayout.PREFERRED_SIZE, 185, GroupLayout.PREFERRED_SIZE)))
						.addGroup(gl_contentPane.createSequentialGroup()
							.addGap(85)
							.addComponent(btnNewButton_1, GroupLayout.PREFERRED_SIZE, 97, GroupLayout.PREFERRED_SIZE))
						.addGroup(gl_contentPane.createSequentialGroup()
							.addPreferredGap(ComponentPlacement.RELATED)
							.addComponent(lblNewLabel, GroupLayout.PREFERRED_SIZE, 196, GroupLayout.PREFERRED_SIZE)))
					.addContainerGap(208, Short.MAX_VALUE))
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(152)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
						.addComponent(lblNewLabel_5_1, GroupLayout.DEFAULT_SIZE, 224, Short.MAX_VALUE)
						.addComponent(lblNewLabel_5, GroupLayout.DEFAULT_SIZE, 223, Short.MAX_VALUE)
						.addComponent(lblNewLabel_4, GroupLayout.DEFAULT_SIZE, 219, Short.MAX_VALUE))
					.addContainerGap(214, GroupLayout.PREFERRED_SIZE))
		);
		gl_contentPane.setVerticalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
						.addGroup(gl_contentPane.createSequentialGroup()
							.addContainerGap()
							.addComponent(btnNewButton_2)
							.addPreferredGap(ComponentPlacement.RELATED)
							.addComponent(btnNewButton_3))
						.addGroup(gl_contentPane.createSequentialGroup()
							.addGap(24)
							.addComponent(lblNewLabel)))
					.addGap(18)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(AdmNametxt, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
						.addComponent(lblNewLabel_1))
					.addGap(3)
					.addComponent(lblNewLabel_4)
					.addPreferredGap(ComponentPlacement.RELATED)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(AdmPasswordtxt, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
						.addComponent(lblNewLabel_2))
					.addPreferredGap(ComponentPlacement.RELATED)
					.addComponent(lblNewLabel_5)
					.addPreferredGap(ComponentPlacement.RELATED)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(AdmPasswordtxtRE, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
						.addComponent(lblNewLabel_3))
					.addGap(4)
					.addComponent(lblNewLabel_5_1)
					.addGap(18)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(btnNewButton)
						.addComponent(btnNewButton_1))
					.addContainerGap(37, Short.MAX_VALUE))
		);
		contentPane.setLayout(gl_contentPane);
		this.setLocationRelativeTo(null);
	}
	private void BackActionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		dispose();
		new RegisterChoose().setVisible(true);
	}

	private void LogInActionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		dispose();
		new LogOnFrm().setVisible(true);
	}

	private void ResetValueActionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		this.resetValue();
	}

	private void resetValue() {
		// TODO Auto-generated method stub
		this.AdmNametxt.setText("");
		this.AdmPasswordtxt.setText("");
		this.AdmPasswordtxtRE.setText("");
	}

	private void RegisterActionPerformed(ActionEvent evt) {
		// TODO Auto-generated method stub
		String userName=this.AdmNametxt.getText();
		String userPassword=new String(this.AdmPasswordtxt.getPassword());
		String userPasswordRE=new String(this.AdmPasswordtxtRE.getPassword());
		if(StringUtil.isEmpty(userName)) {
			JOptionPane.showMessageDialog(null, "账号不能为空！");
			return;
		}
		if(userName.length()>20) {
			JOptionPane.showMessageDialog(null, "账号长度超过限制！");
		}
		if(StringUtil.isEmpty(userPassword)) {
			JOptionPane.showMessageDialog(null, "密码不能为空！");
			return;
		}
		if(userPassword.length()>20) {
			JOptionPane.showMessageDialog(null, "密码长度超过限制！");
		}
		if(StringUtil.isEmpty(userPasswordRE)) {
			JOptionPane.showMessageDialog(null, "请确认密码！");
			return;
		}
		if(!userPassword.equals(userPasswordRE)) {
			JOptionPane.showMessageDialog(null, "两次输入的密码不一致，请重新输入！");
			return;
		}
		User user=new User(userName,userPassword);
		Connection con=null;
		try {
			con=dbUtil.getCon();
			int n=userDao.add(con, user);
			
			if(n==1) {
				JOptionPane.showMessageDialog(null, "注册成功！");
				resetValue();
			}else {
				JOptionPane.showMessageDialog(null, "注册失败！");
			}
		}catch(Exception e) {
			e.printStackTrace();
			JOptionPane.showMessageDialog(null, "注册失败！");
		}finally {
			try {
				dbUtil.closeCon(con);
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}

	
}
