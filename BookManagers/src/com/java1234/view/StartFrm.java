package com.java1234.view;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.LayoutStyle.ComponentPlacement;
import javax.swing.border.EmptyBorder;

public class StartFrm extends JFrame {

	private static final long serialVersionUID = 1L;
	private JPanel contentPane;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			@Override
			public void run() {
				try {
					StartFrm frame = new StartFrm();
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
	public StartFrm() {
		setResizable(false);
		setTitle("身份选择");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 758, 697);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		
		JLabel lblNewLabel = new JLabel("请选择您的登录身份");
		lblNewLabel.setFont(new Font("宋体", Font.BOLD, 25));
		
		JButton btnNewButton = new JButton("管理员登录");
		btnNewButton.setBackground(new Color(255, 255, 128));
		btnNewButton.setFont(new Font("楷体", Font.BOLD, 20));
		btnNewButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				AdminstratorLogActionPerformed(e);
			}
		});
		
		JButton btnNewButton_1 = new JButton("读者登录");
		btnNewButton_1.setBackground(new Color(255, 255, 128));
		btnNewButton_1.setFont(new Font("楷体", Font.BOLD, 20));
		btnNewButton_1.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				ReaderLogAcionPerformed(e);
			}
		});
		
		JLabel lblNewLabel_1 = new JLabel("欢迎来到图书馆管理系统！");
		lblNewLabel_1.setFont(new Font("楷体", Font.BOLD, 30));
		
		JLabel lblNewLabel_2 = new JLabel("Release @ 2023/12");
		
		JLabel lblNewLabel_3 = new JLabel("书是人类进步的阶梯。——高尔基");
		lblNewLabel_3.setFont(new Font("仿宋", Font.BOLD | Font.ITALIC, 15));
		Icon im=new ImageIcon("src\\Image\\IMG_2367(1)-18.jpg");
		JLabel jLabel=new JLabel(im);
		jLabel.setBounds(0, 0, getWidth(), getHeight());
		getContentPane().add(jLabel);
		
		JLabel lblNewLabel_4 = new JLabel("没有账号？注册一个吧");
		lblNewLabel_4.setFont(new Font("宋体", Font.BOLD, 25));
		
		JButton btnNewButton_2 = new JButton("注册");
		btnNewButton_2.setBackground(new Color(255, 255, 128));
		btnNewButton_2.setFont(new Font("楷体", Font.BOLD, 20));
		btnNewButton_2.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				RegisterActionPerformed(e);
			}
		});
		
		JButton btnNewButton_3 = new JButton("访客模式");
		btnNewButton_3.setBackground(new Color(255, 255, 128));
		btnNewButton_3.setFont(new Font("楷体", Font.BOLD, 20));
		btnNewButton_3.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				VisitorActionPerformed(e);
			}
		});

	
		
		GroupLayout gl_contentPane = new GroupLayout(contentPane);
		gl_contentPane.setHorizontalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addContainerGap(213, Short.MAX_VALUE)
					.addComponent(lblNewLabel_1)
					.addGap(127))
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(26)
					.addComponent(lblNewLabel_3, GroupLayout.PREFERRED_SIZE, 249, GroupLayout.PREFERRED_SIZE)
					.addContainerGap(441, Short.MAX_VALUE))
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(133)
					.addComponent(lblNewLabel_4)
					.addGap(31)
					.addComponent(btnNewButton_2, GroupLayout.PREFERRED_SIZE, 97, GroupLayout.PREFERRED_SIZE)
					.addGap(18)
					.addComponent(btnNewButton_3, GroupLayout.PREFERRED_SIZE, 126, GroupLayout.PREFERRED_SIZE)
					.addContainerGap(55, Short.MAX_VALUE))
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(167)
					.addComponent(lblNewLabel, GroupLayout.PREFERRED_SIZE, 248, GroupLayout.PREFERRED_SIZE)
					.addContainerGap(301, Short.MAX_VALUE))
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(238)
					.addComponent(lblNewLabel_2, GroupLayout.PREFERRED_SIZE, 124, GroupLayout.PREFERRED_SIZE)
					.addContainerGap(354, Short.MAX_VALUE))
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(119)
					.addComponent(btnNewButton, GroupLayout.PREFERRED_SIZE, 143, GroupLayout.PREFERRED_SIZE)
					.addPreferredGap(ComponentPlacement.RELATED, 215, Short.MAX_VALUE)
					.addComponent(btnNewButton_1, GroupLayout.PREFERRED_SIZE, 132, GroupLayout.PREFERRED_SIZE)
					.addGap(107))
		);
		gl_contentPane.setVerticalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addContainerGap()
					.addComponent(lblNewLabel_3)
					.addGap(159)
					.addComponent(lblNewLabel_1)
					.addGap(66)
					.addComponent(lblNewLabel, GroupLayout.PREFERRED_SIZE, 40, GroupLayout.PREFERRED_SIZE)
					.addGap(94)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(btnNewButton, GroupLayout.PREFERRED_SIZE, 52, GroupLayout.PREFERRED_SIZE)
						.addComponent(btnNewButton_1, GroupLayout.DEFAULT_SIZE, 50, Short.MAX_VALUE))
					.addGap(50)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(lblNewLabel_4, GroupLayout.PREFERRED_SIZE, 44, GroupLayout.PREFERRED_SIZE)
						.addComponent(btnNewButton_2)
						.addComponent(btnNewButton_3, GroupLayout.PREFERRED_SIZE, 32, GroupLayout.PREFERRED_SIZE))
					.addPreferredGap(ComponentPlacement.RELATED)
					.addComponent(lblNewLabel_2)
					.addGap(61))
		);
		contentPane.setLayout(gl_contentPane);
		//设置JFrame居中显示
		this.setLocationRelativeTo(null);
	}

	private void VisitorActionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		dispose();
		new VisitorMain().setVisible(true);
	}

	private void RegisterActionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		dispose();
		new RegisterChoose().setVisible(true);
	}

	protected void ReaderLogAcionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		dispose();
		new ReaderLogOnFrm().setVisible(true);
	}

	protected void AdminstratorLogActionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		dispose();
		new LogOnFrm().setVisible(true);
	}
}
