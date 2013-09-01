using System;
using SFML.Audio;
using SFML.Window;
using SFML.Graphics;
using System.Diagnostics;  //SFML.NET dropped sf::Time in favor of using C#'s pretty good Stopwatch

namespace RingsOfMadness
{
    class Program
    {
        

        static void Main(string[] args)
        {
            MySFMLProgram app = new MySFMLProgram();
            Console.WriteLine("Yo! Newbs!\nWriting to Debug is done like this, but be aware:\n\t Spamming the Console will result in slow games!!");
            Console.Write("Beginning Game...\n");
            app.StartSFMLProgram();
            
            
        }
    }
    class MySFMLProgram
    {
        Stopwatch timer;
        RenderWindow _window;
        public void StartSFMLProgram()
        {

            timer = new Stopwatch();

            _window = new RenderWindow(new VideoMode(800, 600), "SFML window");
            _window.SetVisible(true);
            _window.Closed += new EventHandler(OnClosed);

            Texture tex = new Texture("resources\\Sprites\\Sharpedo.png");
            Sprite spr = new Sprite(tex);

            Text fps = new Text("Fps is", new Font("resources\\gstbinrm.ttf"));
            fps.DisplayedString = "Fps is this";
            fps.Position = new Vector2f(40f, 20f);

            timer.Start();
            int count = 0;
            while (_window.IsOpen())
            {
                
                if (timer.ElapsedMilliseconds > 0)
                {
                    
                    
                }

                count++;

                if (count > 1000)
                {
                    double time = (double)count / ((double)timer.ElapsedMilliseconds / 1000d);


                    count = 0;
                    timer.Restart();

                    fps.DisplayedString = string.Format("Fps is this: {0}", time);
                }
                
                _window.DispatchEvents();
                _window.Clear(Color.Red);
                _window.Draw(spr);
                _window.Draw(fps);
                _window.Display();
            }
        }
        void OnClosed(object sender, EventArgs e)
        {
            _window.Close();
        }
    }
}