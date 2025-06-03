package com.java1234.view;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.GroupLayout;
import javax.swing.GroupLayout.Alignment;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.LayoutStyle.ComponentPlacement;
import javax.swing.border.EmptyBorder;

public class RegisterChoose extends JFrame {

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
					RegisterChoose frame = new RegisterChoose();
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
	public RegisterChoose() {
		setTitle("注册身份选择");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

		setContentPane(contentPane);
		
		JLabel lblNewLabel = new JLabel("请选择要注册的用户身份：");
		lblNewLabel.setFont(new Font("宋体", Font.BOLD, 20));
		
		JButton btnNewButton = new JButton("管理员注册");
		btnNewButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				AdmRegisterActionPerformed(e);
			}
		});
		btnNewButton.setBackground(new Color(255, 255, 128));
		btnNewButton.setFont(new Font("楷体", Font.BOLD, 20));
		
		JButton btnNewButton_1 = new JButton("读者注册");
		btnNewButton_1.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				ReaderRegisterActionPerformed(e);
			}
		});
		btnNewButton_1.setBackground(new Color(255, 255, 128));
		btnNewButton_1.setFont(new Font("楷体", Font.BOLD, 20));
		
		JButton btnNewButton_2 = new JButton("返回");
		btnNewButton_2.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				BackActionPerformed(e);
			}
		});
		GroupLayout gl_contentPane = new GroupLayout(contentPane);
		gl_contentPane.setHorizontalGroup(
			gl_contentPane.createParallelGroup(Alignment.TRAILING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addContainerGap(142, Short.MAX_VALUE)
					.addComponent(lblNewLabel)
					.addGap(140))
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(89)
					.addComponent(btnNewButton)
					.addPreferredGap(ComponentPlacement.RELATED, 107, Short.MAX_VALUE)
					.addComponent(btnNewButton_1)
					.addGap(84))
				.addGroup(gl_contentPane.createSequentialGroup()
					.addContainerGap(262, Short.MAX_VALUE)
					.addComponent(btnNewButton_2, GroupLayout.PREFERRED_SIZE, 97, GroupLayout.PREFERRED_SIZE)
					.addGap(171))
		);
		gl_contentPane.setVerticalGroup(
			gl_contentPane.createParallelGroup(Alignment.LEADING)
				.addGroup(gl_contentPane.createSequentialGroup()
					.addGap(39)
					.addComponent(lblNewLabel)
					.addPreferredGap(ComponentPlacement.RELATED, 92, Short.MAX_VALUE)
					.addGroup(gl_contentPane.createParallelGroup(Alignment.BASELINE)
						.addComponent(btnNewButton)
						.addComponent(btnNewButton_1))
					.addGap(35)
					.addComponent(btnNewButton_2)
					.addGap(26))
		);
		contentPane.setLayout(gl_contentPane);
		this.setLocationRelativeTo(null);
	}

	private void BackActionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		dispose();
		new StartFrm().setVisible(true);
	}

	private void ReaderRegisterActionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		dispose();
		new ReaderRegister().setVisible(true);
	}

	private void AdmRegisterActionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		dispose();
		new Register().setVisible(true);
	}

}
