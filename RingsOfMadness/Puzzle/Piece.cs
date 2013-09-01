+﻿using System;
+using System.Collections.Generic;
+using System.Linq;
+using System.Text;
+using SFML.Window;
+
+namespace RingsOfMadness.Puzzle
+{
+    class Piece
+    {
+        private static int pieceCount;
+        private int id;
+        public int Id
+        {
+            get
+            {
+                return id;
+            }
+        }
+
+        public enum ports { UP, LEFT, RIGHT, DOWN };
+
+        private List<ports> openPorts;
+
+        public static void resetPieceCount()
+        {
+            pieceCount = 0;
+        }
+        
+        //denied.  Must declare ports on creation
+        private Piece(){}
+
+        /// <summary>
+        /// inits a piece
+        /// </summary>
+        /// <param name="left">declares this port open</param>
+        /// <param name="up">declares this port open</param>
+        /// <param name="right">declares this port open</param>
+        /// <param name="down">declares this port open</param>
+        /// <param name="slice">declares, in radians, how wide this piece is (2pi/piece count)</param>
+        public Piece(bool left, bool up, bool right, bool down, float slice)
+        {
+            pieceCount++;
+            id = pieceCount;
+
+            openPorts = new List<ports>();
+            if (up) openPorts.Add(ports.UP);
+            if (left) openPorts.Add(ports.LEFT);
+            if (right) openPorts.Add(ports.RIGHT);
+            if (down) openPorts.Add(ports.DOWN);
+        }
+
+    }
+}