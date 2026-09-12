#include "MyForm.h"
namespace gui {
System::Void MyForm::label1_Click(System::Object^  sender, System::EventArgs^  e)
{
	}

System::Void MyForm::MyForm_Load(System::Object^  sender, System::EventArgs^  e)
{
	}

System::Void MyForm::pictureBox1_Click(System::Object^  sender, System::EventArgs^  e)
{
	}

System::Void MyForm::trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	label10->Text = System::Convert::ToString(trackBar2->Value);
	aim_ui.fov = System::Convert::ToInt32(trackBar2->Value);
}

System::Void MyForm::trackBar3_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	label12->Text = System::Convert::ToString(trackBar3->Value);
	aim_ui.smooth = System::Convert::ToInt32(trackBar3->Value);
}

System::Void MyForm::trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	label9->Text = System::Convert::ToString(trackBar1->Value);
	trigger_ui.delay = System::Convert::ToInt32(trackBar1->Value);
}

System::Void MyForm::trackBar4_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	label16->Text = System::Convert::ToString(trackBar4->Value);
	visual_ui.alpha = (System::Convert::ToDouble(trackBar4->Value)) / 100;
}

System::Void MyForm::button1_Click_1(System::Object^  sender, System::EventArgs^  e)
{
	button1->BackColor = currentColor;
}

System::Void MyForm::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	button2->BackColor = currentColor;
}

System::Void MyForm::button3_Click(System::Object^  sender, System::EventArgs^  e)
{
	button3->BackColor = currentColor;
}

System::Void MyForm::button4_Click(System::Object^  sender, System::EventArgs^  e)
{
	button4->BackColor = currentColor;
}

System::Void MyForm::checkBox6_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	aim_ui.on = checkBox6->Checked;
}

System::Void MyForm::MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
{
}

System::Void MyForm::button8_Click(System::Object^  sender, System::EventArgs^  e)
{
	memory.Attach(L"Counter-Strike: Global Offensive", PROCESS_ALL_ACCESS);
	scanOffsets();
}

System::Void MyForm::backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e)
{
	Aimbot aimbot;
	virtualesp glowEsp;
	DrawingESP drawingESP;
	while (true)
	{
		aimbot.startAimbot(aim_ui.on, aim_ui.autoFire, getKey(aim_ui.aimKeyIndex), aim_ui.fov, aim_ui.smooth, aim_ui.aimlock);
		aimbot.rcs(aim_ui.rcs);
		triggerbot(trigger_ui.on, trigger_ui.autoFire, getKey(trigger_ui.aimKeyIndex), trigger_ui.delay);
		glowEsp.esp_thread(visual_ui.glow_on, visual_ui.glow_friendly, visual_ui.friendly_glow_color, visual_ui.glow_enemy, visual_ui.enemy_glow_color, visual_ui.visibility_check, visual_ui.visibility_check_color, visual_ui.alpha);
		drawingESP.drawBox(visual_ui.box_esp, visual_ui.box_esp_friendly, visual_ui.box_esp_enemy, visual_ui.box_esp_color, visual_ui.line_esp, visual_ui.name_esp, visual_ui.health_esp, visual_ui.item_esp);
		radarHack(visual_ui.radar_hack);
		noFlash(misc_ui.noFlash);
		afk(misc_ui.afk);
		changeWeaponSkin();
		changeKnife();
		Sleep(1);
	}
}

System::Void MyForm::checkBox9_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	aim_ui.autoFire = checkBox9->Checked;
}

System::Void MyForm::groupBox5_Enter(System::Object^  sender, System::EventArgs^  e)
{

}

System::Void MyForm::radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	aim_ui.aimlock = (radioButton4->Enabled) ? 3 : aim_ui.aimlock;
}

System::Void MyForm::radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	aim_ui.aimlock = (radioButton1->Enabled) ? 0 : aim_ui.aimlock;
}

System::Void MyForm::radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	aim_ui.aimlock = (radioButton2->Enabled) ? 1 : aim_ui.aimlock;
}

System::Void MyForm::radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	aim_ui.aimlock = (radioButton3->Enabled) ? 2 : aim_ui.aimlock;
}

System::Void MyForm::comboBox4_SelectedIndexChanged_1(System::Object^  sender, System::EventArgs^  e)
{
	aim_ui.aimKeyIndex = comboBox4->SelectedIndex;
}

System::Void MyForm::checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	trigger_ui.on = checkBox1->Checked;
}

System::Void MyForm::checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	trigger_ui.autoFire = checkBox2->Checked;
}

System::Void MyForm::comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	trigger_ui.aimKeyIndex = comboBox2->SelectedIndex;
}

System::Void MyForm::pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	System::Drawing::Bitmap^ btm = gcnew System::Drawing::Bitmap(pictureBox1->Image);
	currentColor = btm->GetPixel(e->X, e->Y);

}

System::Void MyForm::checkBox12_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	visual_ui.glow_on = checkBox12->Checked;
}

System::Void MyForm::checkBox13_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	visual_ui.glow_friendly = checkBox13->Checked;
}

System::Void MyForm::button1_BackColorChanged(System::Object^  sender, System::EventArgs^  e)
{
	myColor c = { System::Convert::ToDouble((button1->BackColor).R), System::Convert::ToDouble((button1->BackColor).G), System::Convert::ToDouble((button1->BackColor).B) };
	visual_ui.friendly_glow_color = { c.r / 255, c.g / 255, c.b / 255 };

}

System::Void MyForm::checkBox14_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	visual_ui.glow_enemy = checkBox14->Checked;
}

System::Void MyForm::button2_BackColorChanged(System::Object^  sender, System::EventArgs^  e)
{
	myColor c = { System::Convert::ToDouble((button2->BackColor).R), System::Convert::ToDouble((button2->BackColor).G), System::Convert::ToDouble((button2->BackColor).B) };
	visual_ui.enemy_glow_color = { c.r / 255, c.g / 255, c.b / 255 };
}

System::Void MyForm::checkBox15_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	visual_ui.visibility_check = checkBox15->Checked;
}

System::Void MyForm::button3_BackColorChanged(System::Object^  sender, System::EventArgs^  e)
{
	myColor c = { System::Convert::ToDouble((button3->BackColor).R), System::Convert::ToDouble((button3->BackColor).G), System::Convert::ToDouble((button3->BackColor).B) };
	visual_ui.visibility_check_color = { c.r / 255, c.g / 255, c.b / 255 };
}

System::Void MyForm::checkBox16_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	visual_ui.box_esp = checkBox16->Checked;
}

System::Void MyForm::button4_BackColorChanged(System::Object^  sender, System::EventArgs^  e)
{
	visual_ui.box_esp_color = { System::Convert::ToDouble((button4->BackColor).R), System::Convert::ToDouble((button4->BackColor).G), System::Convert::ToDouble((button4->BackColor).B) };
}

System::Void MyForm::checkBox17_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	visual_ui.name_esp = checkBox17->Checked;
}

System::Void MyForm::checkBox18_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	visual_ui.health_esp = checkBox18->Checked;
}

System::Void MyForm::checkBox19_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	visual_ui.item_esp = checkBox19->Checked;
}

System::Void MyForm::checkBox20_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	visual_ui.line_esp = checkBox20->Checked;
}

System::Void MyForm::checkBox5_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	visual_ui.box_esp_friendly = checkBox5->Checked;
}

System::Void MyForm::checkBox7_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	visual_ui.box_esp_enemy = checkBox7->Checked;
}

System::Void MyForm::checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	visual_ui.radar_hack = checkBox3->Checked;
}

System::Void MyForm::checkBox22_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	misc_ui.bunnyhop = checkBox22->Checked;
	if (misc_ui.bunnyhop)
	{
		bunnyhopThread = gcnew Thread(gcnew ThreadStart(&bunnyHop));
		bunnyhopThread->Start();
	}
	else
	{
		if (bunnyhopThread->IsAlive)
		{
			bunnyhopThread->Abort();
		}
	}
}

System::Void MyForm::checkBox23_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	misc_ui.autoAccept = checkBox23->Checked;
	if (misc_ui.autoAccept)
	{
		autoAcceptThread = gcnew Thread(gcnew ThreadStart(&autoAcceptMatch));
		autoAcceptThread->Start();
	}
	else
	{
		if (autoAcceptThread->IsAlive)
		{
			autoAcceptThread->Abort();
		}
	}
}

System::Void MyForm::checkBox24_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	misc_ui.noFlash = checkBox24->Checked;
}

System::Void MyForm::checkBox26_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	misc_ui.fakeLag = checkBox26->Checked;
	if (misc_ui.fakeLag)
	{
		fakeLagThread = gcnew Thread( gcnew ParameterizedThreadStart( &fakeLag));
		fakeLagThread->Start(misc_ui.fakeLagDelay);
	}
	else
	{
		if (fakeLagThread->IsAlive)
		{
			fakeLagThread->Abort();
		}
	}
}

System::Void MyForm::checkBox4_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	misc_ui.afk = checkBox4->Checked;
}

System::Void MyForm::checkBox21_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
	aim_ui.rcs = checkBox21->Checked;
}

System::Void MyForm::trackBar5_Scroll(System::Object^  sender, System::EventArgs^  e)
{
	label29->Text = System::Convert::ToString(trackBar5->Value);
	misc_ui.fakeLagDelay = trackBar5->Value;
	checkBox26->Checked = false;
}

System::Void MyForm::button5_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (listBox1->SelectedIndex == -1 || listBox2->SelectedIndex == -1)
	{
		return;
	}
	switch (listBox1->SelectedIndex)
	{
	case 0:weapon_skin.Ak47 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 1:weapon_skin.AWP = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 2:weapon_skin.SSG08 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 3:weapon_skin.M4A4 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 4:weapon_skin.M4A1_S = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 5:weapon_skin.FAMAS = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 6:weapon_skin.GalilAR = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 7:weapon_skin.AUG = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 8:weapon_skin.SG553 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 9:weapon_skin.SCAR20 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 10:weapon_skin.G3SG1 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 11:weapon_skin.DesertEagle = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 12:weapon_skin.USP_S = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 13:weapon_skin.Glock18 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 14:weapon_skin.P2000 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 15:weapon_skin.P250 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 16:weapon_skin.FiveSeveN = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 17:weapon_skin.Tec9 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 18:weapon_skin.CZ75Auto = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 19:weapon_skin.DualBerettas = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 20:weapon_skin.R8Revolver = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 21:weapon_skin.MP9 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 22:weapon_skin.MAC10 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 23:weapon_skin.PPBizon = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 24:weapon_skin.MP7 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 25:weapon_skin.UMP45 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 26:weapon_skin.P90 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 27:weapon_skin.MP5SD = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 28:weapon_skin.XM1014 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 29:weapon_skin.Nova = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 30:weapon_skin.MAG7 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 31:weapon_skin.SawedOff = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 32:weapon_skin.M249 = skin_obj[listBox2->SelectedIndex].id;
		break;
	case 33:weapon_skin.Negev = skin_obj[listBox2->SelectedIndex].id;
		break;
	}
	changeWeaponSkin();
	memory.Write<int>(memory.Read<int>(getEnginedll(L"engine.dll") + dwClientState) + 0x174, -1);
}

System::Void MyForm::groupBox6_Enter(System::Object^  sender, System::EventArgs^  e)
{
}

System::Void MyForm::textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	String^ str = gcnew String("");
	for (int i = 0; i < listBox2->Items->Count; i++)
	{
		str = Convert::ToString(listBox2->Items[i]);
		if (str->Equals(textBox2->Text, StringComparison::CurrentCultureIgnoreCase))
		{
			listBox2->SelectedIndex = i;
			break;
		}
		else if (str->StartsWith(textBox2->Text, StringComparison::CurrentCultureIgnoreCase))
		{
			listBox2->SelectedIndex = i;
			break;
		}
	}
}

System::Void MyForm::button6_Click(System::Object^  sender, System::EventArgs^  e)
{
	if (listBox4->SelectedIndex == -1 || listBox3->SelectedIndex == -1)
	{
		return;
	}
	switch (listBox4->SelectedIndex)
	{
	case 0: knife_info.knifeType = WEAPON_KNIFE_BAYONET;
		break;
	case 1: knife_info.knifeType = WEAPON_KNIFE_FLIP;
		break;
	case 2: knife_info.knifeType = WEAPON_KNIFE_GUT;
		break;
	case 3: knife_info.knifeType = WEAPON_KNIFE_KARAMBIT;
		break;
	case 4: knife_info.knifeType = WEAPON_KNIFE_M9_BAYONET;
		break;
	case 5: knife_info.knifeType = WEAPON_KNIFE_TACTICAL;
		break;
	case 6: knife_info.knifeType = WEAPON_KNIFE_FALCHION;
		break;
	case 7: knife_info.knifeType = WEAPON_KNIFE_SURVIVAL_BOWIE;
		break;
	case 8: knife_info.knifeType = WEAPON_KNIFE_BUTTERFLY;
		break;
	case 9: knife_info.knifeType = WEAPON_KNIFE_PUSH;
		break;
	case 10: knife_info.knifeType = WEAPON_KNIFE_URSUS;
		break;
	case 11: knife_info.knifeType = WEAPON_KNIFE_GYPSY_JACKKNIFE;
		break;
	case 12: knife_info.knifeType = WEAPON_KNIFE_STILETTO;
		break;
	case 13: knife_info.knifeType = WEAPON_KNIFE_WIDOWMAKER;
		break;
	}
	knife_info.knifeSkin = listBox3->SelectedIndex;
	changeKnife();
	memory.Write<int>(memory.Read<int>(getEnginedll(L"engine.dll") + dwClientState) + 0x174, -1);
}
}
