/*************************************************************
 * This file was automatically generated on 2011-09-20.      *
 *                                                           *
 * If you have a bugfix for this file and want to commit it, *
 * please fix the bug in the generator. You can find a link  *
 * to the generator git on tinkerforge.com                   *
 *************************************************************/

namespace Tinkerforge
{
	public class BrickletJoystick : Device 
	{
		private static byte TYPE_GET_POSITION = 1;
		private static byte TYPE_IS_PRESSED = 2;
		private static byte TYPE_GET_ANALOG_VALUE = 3;
		private static byte TYPE_CALIBRATE = 4;
		private static byte TYPE_SET_POSITION_CALLBACK_PERIOD = 5;
		private static byte TYPE_GET_POSITION_CALLBACK_PERIOD = 6;
		private static byte TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD = 7;
		private static byte TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD = 8;
		private static byte TYPE_SET_POSITION_CALLBACK_THRESHOLD = 9;
		private static byte TYPE_GET_POSITION_CALLBACK_THRESHOLD = 10;
		private static byte TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD = 11;
		private static byte TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD = 12;
		private static byte TYPE_SET_DEBOUNCE_PERIOD = 13;
		private static byte TYPE_GET_DEBOUNCE_PERIOD = 14;
		private static byte TYPE_POSITION = 15;
		private static byte TYPE_ANALOG_VALUE = 16;
		private static byte TYPE_POSITION_REACHED = 17;
		private static byte TYPE_ANALOG_VALUE_REACHED = 18;
		private static byte TYPE_PRESSED = 19;
		private static byte TYPE_RELEASED = 20;

		public delegate void Position(short x, short y);
		public delegate void AnalogValue(ushort x, ushort y);
		public delegate void PositionReached(short x, short y);
		public delegate void AnalogValueReached(ushort x, ushort y);
		public delegate void Pressed();
		public delegate void Released();

		public BrickletJoystick(string uid) : base(uid) 
		{
			messageCallbacks[TYPE_POSITION] = new MessageCallback(CallbackPosition);
			messageCallbacks[TYPE_ANALOG_VALUE] = new MessageCallback(CallbackAnalogValue);
			messageCallbacks[TYPE_POSITION_REACHED] = new MessageCallback(CallbackPositionReached);
			messageCallbacks[TYPE_ANALOG_VALUE_REACHED] = new MessageCallback(CallbackAnalogValueReached);
			messageCallbacks[TYPE_PRESSED] = new MessageCallback(CallbackPressed);
			messageCallbacks[TYPE_RELEASED] = new MessageCallback(CallbackReleased);
		}

		public void GetPosition(out short x, out short y)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_POSITION, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_POSITION, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetPosition in time");
			}

			x = LEConverter.ShortFrom(4, answer);
			y = LEConverter.ShortFrom(6, answer);

			writeEvent.Set();
		}

		public void IsPressed(out bool pressed)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_IS_PRESSED, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_IS_PRESSED, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for IsPressed in time");
			}

			pressed = LEConverter.BoolFrom(4, answer);

			writeEvent.Set();
		}

		public void GetAnalogValue(out ushort x, out ushort y)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_ANALOG_VALUE, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_ANALOG_VALUE, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetAnalogValue in time");
			}

			x = LEConverter.UShortFrom(4, answer);
			y = LEConverter.UShortFrom(6, answer);

			writeEvent.Set();
		}

		public void Calibrate()
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_CALIBRATE, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_CALIBRATE, false);
		}

		public void SetPositionCallbackPeriod(uint period)
		{
			byte[] data = new byte[8];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_SET_POSITION_CALLBACK_PERIOD, 1, data);
			LEConverter.To((ushort)8, 2, data);
			LEConverter.To(period, 4, data);

			ipcon.Write(this, data, TYPE_SET_POSITION_CALLBACK_PERIOD, false);
		}

		public void GetPositionCallbackPeriod(out uint period)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_POSITION_CALLBACK_PERIOD, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_POSITION_CALLBACK_PERIOD, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetPositionCallbackPeriod in time");
			}

			period = LEConverter.UIntFrom(4, answer);

			writeEvent.Set();
		}

		public void SetAnalogValueCallbackPeriod(uint period)
		{
			byte[] data = new byte[8];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD, 1, data);
			LEConverter.To((ushort)8, 2, data);
			LEConverter.To(period, 4, data);

			ipcon.Write(this, data, TYPE_SET_ANALOG_VALUE_CALLBACK_PERIOD, false);
		}

		public void GetAnalogValueCallbackPeriod(out uint period)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_ANALOG_VALUE_CALLBACK_PERIOD, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetAnalogValueCallbackPeriod in time");
			}

			period = LEConverter.UIntFrom(4, answer);

			writeEvent.Set();
		}

		public void SetPositionCallbackThreshold(char option, short minX, short maxX, short minY, short maxY)
		{
			byte[] data = new byte[13];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_SET_POSITION_CALLBACK_THRESHOLD, 1, data);
			LEConverter.To((ushort)13, 2, data);
			LEConverter.To(option, 4, data);
			LEConverter.To(minX, 5, data);
			LEConverter.To(maxX, 7, data);
			LEConverter.To(minY, 9, data);
			LEConverter.To(maxY, 11, data);

			ipcon.Write(this, data, TYPE_SET_POSITION_CALLBACK_THRESHOLD, false);
		}

		public void GetPositionCallbackThreshold(out char option, out short minX, out short maxX, out short minY, out short maxY)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_POSITION_CALLBACK_THRESHOLD, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_POSITION_CALLBACK_THRESHOLD, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetPositionCallbackThreshold in time");
			}

			option = LEConverter.CharFrom(4, answer);
			minX = LEConverter.ShortFrom(5, answer);
			maxX = LEConverter.ShortFrom(7, answer);
			minY = LEConverter.ShortFrom(9, answer);
			maxY = LEConverter.ShortFrom(11, answer);

			writeEvent.Set();
		}

		public void SetAnalogValueCallbackThreshold(char option, ushort minX, ushort maxX, ushort minY, ushort maxY)
		{
			byte[] data = new byte[13];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD, 1, data);
			LEConverter.To((ushort)13, 2, data);
			LEConverter.To(option, 4, data);
			LEConverter.To(minX, 5, data);
			LEConverter.To(maxX, 7, data);
			LEConverter.To(minY, 9, data);
			LEConverter.To(maxY, 11, data);

			ipcon.Write(this, data, TYPE_SET_ANALOG_VALUE_CALLBACK_THRESHOLD, false);
		}

		public void GetAnalogValueCallbackThreshold(out char option, out ushort minX, out ushort maxX, out ushort minY, out ushort maxY)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_ANALOG_VALUE_CALLBACK_THRESHOLD, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetAnalogValueCallbackThreshold in time");
			}

			option = LEConverter.CharFrom(4, answer);
			minX = LEConverter.UShortFrom(5, answer);
			maxX = LEConverter.UShortFrom(7, answer);
			minY = LEConverter.UShortFrom(9, answer);
			maxY = LEConverter.UShortFrom(11, answer);

			writeEvent.Set();
		}

		public void SetDebouncePeriod(uint debounce)
		{
			byte[] data = new byte[8];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_SET_DEBOUNCE_PERIOD, 1, data);
			LEConverter.To((ushort)8, 2, data);
			LEConverter.To(debounce, 4, data);

			ipcon.Write(this, data, TYPE_SET_DEBOUNCE_PERIOD, false);
		}

		public void GetDebouncePeriod(out uint debounce)
		{
			byte[] data = new byte[4];
			LEConverter.To(stackID, 0, data);
			LEConverter.To(TYPE_GET_DEBOUNCE_PERIOD, 1, data);
			LEConverter.To((ushort)4, 2, data);

			ipcon.Write(this, data, TYPE_GET_DEBOUNCE_PERIOD, true);

			byte[] answer;
			if(!answerQueue.TryDequeue(out answer, IPConnection.TIMEOUT_ANSWER))
			{
				throw new TimeoutException("Did not receive answer for GetDebouncePeriod in time");
			}

			debounce = LEConverter.UIntFrom(4, answer);

			writeEvent.Set();
		}

		public int CallbackPosition(byte[] data)
		{
			short x = LEConverter.ShortFrom(4, data);
			short y = LEConverter.ShortFrom(6, data);

			((Position)callbacks[TYPE_POSITION])(x, y);
			return 8;
		}

		public int CallbackAnalogValue(byte[] data)
		{
			ushort x = LEConverter.UShortFrom(4, data);
			ushort y = LEConverter.UShortFrom(6, data);

			((AnalogValue)callbacks[TYPE_ANALOG_VALUE])(x, y);
			return 8;
		}

		public int CallbackPositionReached(byte[] data)
		{
			short x = LEConverter.ShortFrom(4, data);
			short y = LEConverter.ShortFrom(6, data);

			((PositionReached)callbacks[TYPE_POSITION_REACHED])(x, y);
			return 8;
		}

		public int CallbackAnalogValueReached(byte[] data)
		{
			ushort x = LEConverter.UShortFrom(4, data);
			ushort y = LEConverter.UShortFrom(6, data);

			((AnalogValueReached)callbacks[TYPE_ANALOG_VALUE_REACHED])(x, y);
			return 8;
		}

		public int CallbackPressed(byte[] data)
		{
			((Pressed)callbacks[TYPE_PRESSED])();
			return 4;
		}

		public int CallbackReleased(byte[] data)
		{
			((Released)callbacks[TYPE_RELEASED])();
			return 4;
		}

		public void RegisterCallback(System.Delegate d)
		{
			if(d.GetType() == typeof(Position))
			{
				callbacks[TYPE_POSITION] = d;
			}
			else if(d.GetType() == typeof(AnalogValue))
			{
				callbacks[TYPE_ANALOG_VALUE] = d;
			}
			else if(d.GetType() == typeof(PositionReached))
			{
				callbacks[TYPE_POSITION_REACHED] = d;
			}
			else if(d.GetType() == typeof(AnalogValueReached))
			{
				callbacks[TYPE_ANALOG_VALUE_REACHED] = d;
			}
			else if(d.GetType() == typeof(Pressed))
			{
				callbacks[TYPE_PRESSED] = d;
			}
			else if(d.GetType() == typeof(Released))
			{
				callbacks[TYPE_RELEASED] = d;
			}
		}
	}
}
