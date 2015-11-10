
using UnityEngine;
using System.Collections;
using System.IO.Ports;

public class ArduinoCMD : MonoBehaviour
{
	
	SerialPort port = new SerialPort("COM4", 9600);
	string donneeArduino = "";
	
	// Use this for initialization
	void Start ()
	{
        port.Close();
		//port.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);
        port.Open();
	}
	
	// Update is called once per frame
	void Update ()
	{		
		donneeArduino = port.ReadLine();
		Debug.Log(donneeArduino);
		
		switch (donneeArduino)
		{
		case "1" :
			this.transform.Translate(Vector3.forward * Time.deltaTime);
			break;
		case "2" :
			this.transform.Translate(Vector3.back * Time.deltaTime);
			break;
		case "3" :
			this.transform.Translate(Vector3.up * Time.deltaTime);
			break;
		case "4" :
			this.transform.Translate(Vector3.down * Time.deltaTime);
			break;
		default :
			Debug.Log("Je suis en pause");
			break;
		}
	}
	
	 private void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
	{
		//SerialPort portSerie = (SerialPort)sender;
		//string donneeArduino = portSerie.ReadLine();
	}
	
	void OnApplicationQuit()
	{
		port.Close();
	}

}
