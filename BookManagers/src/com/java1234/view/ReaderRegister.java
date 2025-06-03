package com.java1234.view;

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

import com.java1234.dao.ReaderDao;
import com.java1234.model.Reader;
import com.java1234.util.DbUtil;
import com.java1234.util.StringUtil;

public class ReaderRegister extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;
	private JTextField readerNametxt;
	private JPasswordField readerPasswordtxt;
	private JPasswordField readerPasswordtxtRE;
	
	private DbUtil dbUtil=new DbUtil();
	private ReaderDao readerDao=new ReaderDao();

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			@Override
			public void run() {
				try {
					ReaderRegister frame = new ReaderRegister();
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
	public ReaderRegister() {
		setTitle("注册——读者注册");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 477, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		
		JLabel lblNewLabel = new JLabel("欢迎来到读者注册");
		lblNewLabel.setFont(new Font("宋体", Font.BOLD, 20));
		
		JLabel lblNewLabel_1 = new JLabel("账    号：");
		lblNewLabel_1.setFont(new Font("宋体", Font.BOLD, 15));
		
		JLabel lblNewLabel_2 = new JLabel("密    码：");
		lblNewLabel_2.setFont(new Font("宋体", Font.BOLD, 15));
		
		JLabel lblNewLabel_3 = new JLabel("确认密码：");
		lblNewLabel_3.setFont(new Font("宋体", Font.BOLD, 15));
		
		readerNametxt = new JTextField();
		readerNametxt.setColumns(10);
		
		readerPasswordtxt = new JPasswordField();
		
		readerPasswordtxtRE = new JPasswordField();
		
		JButton btnNewButton = new JButton("注    册");
		btnNewButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				readerRegisterActionPerformed(e);
			}
		});
		
		JButton btnNewButton_1 = new JButton("重    置");
		btnNewButton_1.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				ResetValueActionPerformed(e);
			}
		});
		
		JLabel lblNewLabel_4 = new JLabel("（20个字符以内的数字、字母组合）");
		
		JLabel lblNewLabel_4_1 = new JLabel("（20个字符以内的数字、字母组合）");
		
		JLabel lblNewLabel_4_1_1 = new JLabel("（20个字符以内的数字、字母组合）");
		
		JButton btnNewButton_2 = new JButton("点此登录");
		btnNewButton_2.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				ReaderLogInActionPerformed(e);
			}
		});
		
		JButton btnNewButton_3 = new JButton("返回");
		btnNewButton_3.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				ReaderBackActionPerformed(e);
			}
		});
		GroupLayout gl_contentPane = new GroupLayout(contentPane);
		gl_contentPane.setHorizontalGroup(
			gl_contentPane.createParallelGroup(Alignment.TRAILING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(60)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.TRAILING)
						.addComponent(btnNewButton, GroupLayout.PREFERRED_SIZE, 97, GroupLayout.PREFERRED_SIZE)
						.addGroup(gl_contentPane.createSequentialGroup()
							.addComponent(lblNewLabel_3)
							.addPreferredGap(ComponentPlacement.RELATED))
						.addGroup(gl_contentPane.createSequentialGroup()
							.addGroup(gl_contentPane.createParallelGroup(Alignment.TRAILING)
								.addComponent(lblNewLabel_2)
								.addComponent(lblNewLabel_1))
							.addPreferredGap(ComponentPlacement.RELATED)))
					.addGap(58)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.TRAILING)
						.addComponent(readerPasswordtxt, Alignment.LEADING, GroupLayout.PREFERRED_SIZE, 178, GroupLayout.PREFERRED_SIZE)
						.addComponent(readerPasswordtxtRE, Alignment.LEADING, GroupLayout.PREFERRED_SIZE, 179, GroupLayout.PREFERRED_SIZE)
						.addComponent(readerNametxt, Alignment.LEADING, GroupLayout.PREFERRED_SIZE, 177, GroupLayout.PREFERRED_SIZE)
						.addComponent(lblNewLabel_4, Alignment.LEADING, GroupLayout.DEFAULT_SIZE, 219, Short.MAX_VALUE)
						.addComponent(lblNewLabel_4_1_1, Alignment.LEADING, GroupLayout.DEFAULT_SIZE, 219, Short.MAX_VALUE)
						.addComponent(lblNewLabel_4_1, Alignment.LEADING, GroupLayout.DEFAULT_SIZE, 219, Short.MAX_VALUE)
						.addGroup(gl_contentPane.createSequentialGroup()
							.addPreferredGap(ComponentPlacement.RELATED)
							.addComponent(btnNewButton_1, GroupLayout.PREFERRED_SIZE, 97, GroupLayout.PREFERRED_SIZE)))
					.addGap(49))
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(20)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
						.addComponent(btnNewButton_2, GroupLayout.PREFERRED_SIZE, 97, GroupLayout.PREFERRED_SIZE)
						.addComponent(btnNewButton_3, GroupLayout.PREFERRED_SIZE, 97, GroupLayout.PREFERRED_SIZE))
					.addPreferredGap(ComponentPlacement.RELATED, 57, Short.MAX_VALUE)
					.addComponent(lblNewLabel)
					.addGap(144))
		);
		gl_contentPane.setVerticalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGroup(gl_contentPane.createParallelGroup(Alignment.LEADING)
						.addGroup(gl_contentPane.createSequentialGroup()
							.addContainerGap()
							.addComponent(lblNewLabel))
						.addComponent(btnNewButton_2))
					.addGap(30)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(readerNametxt, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
						.addComponent(lblNewLabel_1))
					.addPreferredGap(ComponentPlacement.RELATED)
					.addComponent(lblNewLabel_4)
					.addGap(8)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(readerPasswordtxt, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE)
						.addComponent(lblNewLabel_2))
					.addPreferredGap(ComponentPlacement.RELATED)
					.addComponent(lblNewLabel_4_1)
					.addGap(10)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblNewLabel_3)
						.addComponent(readerPasswordtxtRE, GroupLayout.PREFERRED_SIZE, GroupLayout.DEFAULT_SIZE, GroupLayout.PREFERRED_SIZE))
					.addPreferredGap(ComponentPlacement.RELATED)
					.addComponent(lblNewLabel_4_1_1)
					.addPreferredGap(ComponentPlacement.RELATED, 12, Short.MAX_VALUE)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(btnNewButton)
						.addComponent(btnNewButton_1))
					.addContainerGap())
				.addGroup(Alignment.TRAILING, gl_contentPane.createSequentialGroup()
					.addContainerGap(33, Short.MAX_VALUE)
					.addComponent(btnNewButton_3)
					.addGap(199))
		);
		contentPane.setLayout(gl_contentPane);
		this.setLocationRelativeTo(null);
	}

	private void ReaderBackActionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		dispose();
		new RegisterChoose().setVisible(true);
	}

	private void ReaderLogInActionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		dispose();
		new ReaderLogOnFrm().setVisible(true);
	}

	private void readerRegisterActionPerformed(ActionEvent evt) {
		// TODO Auto-generated method stub
		String readerName=this.readerNametxt.getText();
		String readerPassword=new String(this.readerPasswordtxt.getPassword());
		String readerPasswordRE=new String(this.readerPasswordtxtRE.getPassword());
		if(StringUtil.isEmpty(readerName)) {
			JOptionPane.showMessageDialog(null, "账号不能为空！");
			return;
		}
		if(readerName.length()>20) {
			JOptionPane.showMessageDialog(null, "账号长度超过限制！");
			return;
		}
		if(StringUtil.isEmpty(readerPassword)) {
			JOptionPane.showMessageDialog(null, "密码不能为空！");
			return;
		}
		if(readerPassword.length()>20) {
			JOptionPane.showMessageDialog(null, "密码长度超过限制！");
			return;
		}
		if(StringUtil.isEmpty(readerPasswordRE)) {
			JOptionPane.showMessageDialog(null, "请确认密码！");
			return;
		}
		if(!readerPassword.equals(readerPasswordRE)) {
			JOptionPane.showMessageDialog(null, "两次输入的密码不一致，请重新输入！");
			return;
		}
		Reader reader=new Reader(readerName,readerPassword);
		Connection con=null;
		try {
			con=dbUtil.getCon();
			int n=readerDao.add(con, reader);
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

	private void ResetValueActionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		this.resetValue();
	}
	private void resetValue() {
		this.readerNametxt.setText("");
		this.readerPasswordtxt.setText("");
		this.readerPasswordtxtRE.setText("");
	}
}
