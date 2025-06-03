package com.java1234.view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;

import javax.swing.JInternalFrame;
import javax.swing.JLabel;

public class AboutSystemInterFrm extends JInternalFrame {

	private static final long serialVersionUID = 1L;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			@Override
			public void run() {
				try {
					AboutSystemInterFrm frame = new AboutSystemInterFrm();
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
	public AboutSystemInterFrm() {
		getContentPane().setBackground(new Color(255, 255, 128));
		setIconifiable(true);
		setClosable(true);
		setTitle("关于此系统");
		setBounds(100, 100, 450, 300);
		getContentPane().setLayout(new BorderLayout(0, 0));
		
		JLabel lblNewLabel = new JLabel("图书信息管理系统");
		lblNewLabel.setFont(new Font("宋体", Font.BOLD, 25));
		getContentPane().add(lblNewLabel, BorderLayout.CENTER);

	}
}
