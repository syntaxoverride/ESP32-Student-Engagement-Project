#ifndef SPLASH_HTML_H
#define SPLASH_HTML_H

#include <Arduino.h>

const char SPLASH_HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>VAULTGUARD AI PORTAL</title>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Orbitron:wght@400;700;900&family=Rajdhani:wght@300;400;600;700&display=swap');
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }
        body {
            font-family: 'Rajdhani', 'Courier New', 'Consolas', 'Monaco', monospace;
            background: #0a0a0a;
            background-image: 
                linear-gradient(0deg, transparent 24%, rgba(0,255,255,0.05) 25%, rgba(0,255,255,0.05) 26%, transparent 27%, transparent 74%, rgba(0,255,255,0.05) 75%, rgba(0,255,255,0.05) 76%, transparent 77%, transparent),
                linear-gradient(90deg, transparent 24%, rgba(0,255,255,0.05) 25%, rgba(0,255,255,0.05) 26%, transparent 27%, transparent 74%, rgba(0,255,255,0.05) 75%, rgba(0,255,255,0.05) 76%, transparent 77%, transparent);
            background-size: 50px 50px;
            color: #00ffff;
            min-height: 100vh;
            display: flex;
            align-items: center;
            justify-content: center;
            position: relative;
            overflow: hidden;
        }
        body::before {
            content: '';
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            height: 100%;
            background: linear-gradient(180deg, rgba(0,255,255,0.1) 0%, transparent 50%, rgba(255,0,255,0.1) 100%);
            pointer-events: none;
            z-index: 0;
        }
        .container {
            position: relative;
            z-index: 1;
            text-align: center;
            padding: 20px;
            max-width: 800px;
            width: 100%;
        }
        h1 {
            font-family: 'Orbitron', monospace;
            font-size: 32px;
            font-weight: 900;
            color: #00ffff;
            text-transform: uppercase;
            letter-spacing: 4px;
            margin-bottom: 10px;
            text-shadow: 
                0 0 10px rgba(0,255,255,0.8),
                0 0 20px rgba(0,255,255,0.6),
                0 0 30px rgba(0,255,255,0.4);
            animation: pulse 2s ease-in-out infinite;
        }
        @keyframes pulse {
            0%, 100% { opacity: 1; }
            50% { opacity: 0.8; }
        }
        .subtitle {
            font-size: 14px;
            color: rgba(0,255,255,0.7);
            letter-spacing: 2px;
            margin-bottom: 50px;
            text-transform: uppercase;
        }
        .menu-grid {
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
            gap: 30px;
            margin-top: 40px;
        }
        .menu-square {
            aspect-ratio: 1;
            background: rgba(0,255,255,0.05);
            border: 3px solid #00ffff;
            border-radius: 0;
            cursor: pointer;
            transition: all 0.3s;
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            padding: 30px;
            text-decoration: none;
            color: #00ffff;
            position: relative;
            overflow: hidden;
            box-shadow: 
                0 0 20px rgba(0,255,255,0.3),
                inset 0 0 20px rgba(0,255,255,0.1);
        }
        .menu-square::before {
            content: '';
            position: absolute;
            top: -50%;
            left: -50%;
            width: 200%;
            height: 200%;
            background: linear-gradient(45deg, transparent, rgba(0,255,255,0.1), transparent);
            transform: rotate(45deg);
            transition: all 0.5s;
        }
        .menu-square:hover {
            border-color: #ff00ff;
            box-shadow: 
                0 0 30px rgba(255,0,255,0.6),
                0 0 50px rgba(255,0,255,0.4),
                inset 0 0 30px rgba(255,0,255,0.2);
            transform: translateY(-5px) scale(1.02);
        }
        .menu-square:hover::before {
            animation: shine 1s ease-in-out;
        }
        @keyframes shine {
            0% { transform: translateX(-100%) translateY(-100%) rotate(45deg); }
            100% { transform: translateX(100%) translateY(100%) rotate(45deg); }
        }
        .menu-square.cyber {
            border-color: #00ffff;
        }
        .menu-square.cyber:hover {
            border-color: #00ffff;
            box-shadow: 
                0 0 40px rgba(0,255,255,0.8),
                0 0 60px rgba(0,255,255,0.6),
                inset 0 0 30px rgba(0,255,255,0.3);
        }
        .menu-square.sensor {
            border-color: #00ff00;
        }
        .menu-square.sensor:hover {
            border-color: #00ff00;
            box-shadow: 
                0 0 40px rgba(0,255,0,0.8),
                0 0 60px rgba(0,255,0,0.6),
                inset 0 0 30px rgba(0,255,0,0.3);
        }
        .menu-icon {
            font-size: 64px;
            margin-bottom: 20px;
            font-family: 'Orbitron', monospace;
            font-weight: 900;
            text-shadow: 0 0 20px currentColor;
        }
        .menu-title {
            font-family: 'Orbitron', monospace;
            font-size: 24px;
            font-weight: 700;
            text-transform: uppercase;
            letter-spacing: 3px;
            margin-bottom: 10px;
            color: inherit;
        }
        .menu-description {
            font-size: 14px;
            color: rgba(255,255,255,0.7);
            line-height: 1.5;
            text-align: center;
        }
        .menu-square.cyber .menu-icon {
            color: #00ffff;
        }
        .menu-square.sensor .menu-icon {
            color: #00ff00;
        }
        @media (max-width: 600px) {
            h1 {
                font-size: 24px;
            }
            .menu-grid {
                grid-template-columns: 1fr;
                gap: 20px;
            }
            .menu-square {
                padding: 20px;
            }
            .menu-icon {
                font-size: 48px;
            }
            .menu-title {
                font-size: 20px;
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>VAULTGUARD AI PORTAL</h1>
        <p class="subtitle">VAULTGUARD.AI // ACCESS: VAULTGUARD.LOCAL</p>
        
        <div class="menu-grid">
            <a href="/vaultguard" class="menu-square cyber">
                <div class="menu-icon">⚡</div>
                <div class="menu-title">VaultGuard AI</div>
                <div class="menu-description">AI Phishing Detector<br>Analyze messages for security threats</div>
            </a>
            
            <a href="/security" class="menu-square sensor">
                <div class="menu-icon">🔒</div>
                <div class="menu-title">Security Center</div>
                <div class="menu-description">Bank Vault Security System<br>Access control & intrusion detection</div>
            </a>
        </div>
    </div>
</body>
</html>
)rawliteral";

#endif
