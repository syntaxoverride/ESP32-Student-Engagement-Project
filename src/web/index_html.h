#ifndef INDEX_HTML_H
#define INDEX_HTML_H

#include <Arduino.h>

const char INDEX_HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>VAULTGUARD AI // PHISHING DETECTOR</title>
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Orbitron:wght@400;700;900&family=Rajdhani:wght@300;400;600;700&display=swap');
        :root {
            --primary-color: #00ffff;
            --secondary-color: #ff00ff;
            --accent-color: #00ff00;
            --background-color: #0a0a0a;
            --text-color: #00ffff;
        }
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }
        body {
            font-family: 'Rajdhani', 'Courier New', 'Consolas', 'Monaco', monospace;
            background: var(--background-color);
            background-image: 
                linear-gradient(0deg, transparent 24%, rgba(0,255,255,0.05) 25%, rgba(0,255,255,0.05) 26%, transparent 27%, transparent 74%, rgba(0,255,255,0.05) 75%, rgba(0,255,255,0.05) 76%, transparent 77%, transparent),
                linear-gradient(90deg, transparent 24%, rgba(0,255,255,0.05) 25%, rgba(0,255,255,0.05) 26%, transparent 27%, transparent 74%, rgba(0,255,255,0.05) 75%, rgba(0,255,255,0.05) 76%, transparent 77%, transparent);
            background-size: 50px 50px;
            color: #00ffff;
            line-height: 1.6;
            padding: 10px;
            position: relative;
            overflow-x: hidden;
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
            max-width: 900px;
            margin: 0 auto;
            background: rgba(10,10,20,0.95);
            border: 2px solid #00ffff;
            border-radius: 0;
            box-shadow: 
                0 0 20px rgba(0,255,255,0.5),
                inset 0 0 20px rgba(0,255,255,0.1);
            padding: 20px;
            margin-bottom: 20px;
            position: relative;
            z-index: 1;
        }
        h1 {
            font-family: 'Orbitron', 'Courier New', 'Consolas', 'Monaco', monospace;
            color: #00ffff;
            text-align: center;
            margin-bottom: 10px;
            font-size: 28px;
            font-weight: 900;
            text-transform: uppercase;
            letter-spacing: 3px;
            text-shadow: 
                0 0 10px #00ffff,
                0 0 20px #00ffff,
                0 0 30px #00ffff;
            animation: pulse 2s ease-in-out infinite;
        }
        @keyframes pulse {
            0%, 100% { opacity: 1; }
            50% { opacity: 0.8; }
        }
        .subtitle {
            text-align: center;
            color: #ff00ff;
            font-size: 14px;
            margin-bottom: 20px;
            font-weight: 600;
            letter-spacing: 2px;
            text-shadow: 0 0 10px rgba(255,0,255,0.8);
        }
        .input-section {
            margin-bottom: 20px;
        }
        label {
            display: block;
            margin-bottom: 8px;
            font-weight: 600;
            color: #00ffff;
            font-size: 16px;
            text-transform: uppercase;
            letter-spacing: 1px;
            text-shadow: 0 0 5px rgba(0,255,255,0.5);
        }
        textarea {
            width: 100%;
            min-height: 120px;
            padding: 12px;
            background: rgba(0,0,0,0.8);
            border: 2px solid #00ffff;
            border-radius: 0;
            font-size: 16px;
            font-family: 'Courier New', monospace;
            color: #00ff00;
            resize: vertical;
            box-shadow: 
                0 0 10px rgba(0,255,255,0.3),
                inset 0 0 10px rgba(0,255,255,0.1);
        }
        textarea:focus {
            outline: none;
            border-color: #ff00ff;
            box-shadow: 
                0 0 20px rgba(255,0,255,0.5),
                inset 0 0 20px rgba(255,0,255,0.1);
        }
        textarea::placeholder {
            color: rgba(0,255,255,0.4);
        }
        .samples {
            margin-bottom: 20px;
        }
        .samples h3 {
            font-size: 16px;
            margin-bottom: 10px;
            color: #00ffff;
            text-transform: uppercase;
            letter-spacing: 1px;
            text-shadow: 0 0 5px rgba(0,255,255,0.5);
        }
        .sample-chips {
            display: flex;
            flex-wrap: wrap;
            gap: 8px;
        }
        .sample-chip {
            background: rgba(0,255,255,0.1);
            border: 1px solid #00ffff;
            border-radius: 0;
            padding: 8px 16px;
            font-size: 13px;
            cursor: pointer;
            transition: all 0.3s;
            user-select: none;
            color: #00ffff;
            font-weight: 600;
            text-transform: uppercase;
            letter-spacing: 1px;
            box-shadow: 0 0 5px rgba(0,255,255,0.3);
        }
        .sample-chip:hover {
            background: rgba(0,255,255,0.3);
            color: #ffffff;
            border-color: #ff00ff;
            box-shadow: 
                0 0 15px rgba(0,255,255,0.8),
                0 0 25px rgba(255,0,255,0.5);
            transform: translateY(-2px);
        }
        .sample-chip:active {
            transform: scale(0.95) translateY(0);
        }
        .button-group {
            display: flex;
            gap: 10px;
            margin-bottom: 20px;
        }
        button {
            flex: 1;
            padding: 14px 20px;
            font-size: 16px;
            font-weight: 600;
            border: none;
            border-radius: 6px;
            cursor: pointer;
            transition: all 0.2s;
            min-height: 48px;
        }
        .btn-primary {
            background: linear-gradient(135deg, #00ffff 0%, #0080ff 100%);
            color: #000;
            font-weight: 700;
            text-transform: uppercase;
            letter-spacing: 2px;
            border: 2px solid #00ffff;
            box-shadow: 
                0 0 15px rgba(0,255,255,0.6),
                inset 0 0 15px rgba(255,255,255,0.2);
            position: relative;
            overflow: hidden;
        }
        .btn-primary::before {
            content: '';
            position: absolute;
            top: 50%;
            left: 50%;
            width: 0;
            height: 0;
            border-radius: 50%;
            background: rgba(255,255,255,0.3);
            transform: translate(-50%, -50%);
            transition: width 0.6s, height 0.6s;
        }
        .btn-primary:hover::before {
            width: 300px;
            height: 300px;
        }
        .btn-primary:hover {
            box-shadow: 
                0 0 25px rgba(0,255,255,1),
                0 0 50px rgba(0,255,255,0.6),
                inset 0 0 25px rgba(255,255,255,0.3);
            transform: translateY(-2px);
        }
        .btn-primary:active {
            transform: translateY(0);
        }
        .btn-primary:disabled {
            background: rgba(100,100,100,0.3);
            color: rgba(255,255,255,0.3);
            border-color: rgba(255,255,255,0.2);
            cursor: not-allowed;
            box-shadow: none;
        }
        .btn-secondary {
            background: rgba(255,0,255,0.2);
            color: #ff00ff;
            border: 2px solid #ff00ff;
            font-weight: 700;
            text-transform: uppercase;
            letter-spacing: 2px;
            box-shadow: 0 0 10px rgba(255,0,255,0.4);
        }
        .btn-secondary:hover {
            background: rgba(255,0,255,0.4);
            box-shadow: 
                0 0 20px rgba(255,0,255,0.8),
                0 0 40px rgba(255,0,255,0.4);
            transform: translateY(-2px);
        }
        .strictness-control {
            margin-bottom: 20px;
            padding: 15px;
            background: rgba(0,0,0,0.5);
            border: 1px solid #00ffff;
            border-radius: 0;
            box-shadow: 0 0 10px rgba(0,255,255,0.3);
        }
        .strictness-control label {
            display: block;
            margin-bottom: 10px;
            font-size: 14px;
        }
        .strictness-buttons {
            display: flex;
            gap: 8px;
        }
        .strictness-btn {
            flex: 1;
            padding: 10px;
            font-size: 13px;
            background: rgba(0,255,255,0.1);
            border: 1px solid #00ffff;
            border-radius: 0;
            cursor: pointer;
            color: #00ffff;
            font-weight: 600;
            text-transform: uppercase;
            letter-spacing: 1px;
            transition: all 0.3s;
        }
        .strictness-btn:hover {
            background: rgba(0,255,255,0.2);
            box-shadow: 0 0 10px rgba(0,255,255,0.5);
        }
        .strictness-btn.active {
            background: linear-gradient(135deg, #00ffff 0%, #0080ff 100%);
            color: #000;
            border-color: #00ffff;
            box-shadow: 
                0 0 15px rgba(0,255,255,0.8),
                inset 0 0 10px rgba(255,255,255,0.2);
            font-weight: 700;
        }
        .results {
            display: none;
            margin-top: 20px;
            padding: 20px;
            border-radius: 6px;
            animation: fadeIn 0.3s;
        }
        @keyframes fadeIn {
            from { opacity: 0; transform: translateY(-10px); }
            to { opacity: 1; transform: translateY(0); }
        }
        .results.safe {
            background: rgba(0,255,0,0.1);
            border: 2px solid #00ff00;
            box-shadow: 
                0 0 20px rgba(0,255,0,0.5),
                inset 0 0 20px rgba(0,255,0,0.1);
        }
        .results.suspicious {
            background: rgba(255,0,0,0.1);
            border: 2px solid #ff0000;
            box-shadow: 
                0 0 20px rgba(255,0,0,0.5),
                inset 0 0 20px rgba(255,0,0,0.1);
        }
        .verdict {
            font-size: 28px;
            font-weight: 900;
            margin-bottom: 10px;
            text-align: center;
            font-family: 'Orbitron', 'Courier New', 'Consolas', 'Monaco', monospace;
            text-transform: uppercase;
            letter-spacing: 3px;
            text-shadow: 0 0 10px currentColor;
        }
        .score {
            text-align: center;
            font-size: 48px;
            font-weight: 900;
            margin: 15px 0;
            font-family: 'Orbitron', 'Courier New', 'Consolas', 'Monaco', monospace;
            text-shadow: 0 0 20px currentColor;
            animation: pulse 2s ease-in-out infinite;
        }
        .score-bar {
            width: 100%;
            height: 30px;
            background: #ecf0f1;
            border-radius: 15px;
            overflow: hidden;
            margin: 15px 0;
        }
        .score-fill {
            height: 100%;
            transition: width 0.5s;
            border-radius: 15px;
        }
        .score-fill.safe {
            background: linear-gradient(90deg, #00ff00 0%, #00cc00 100%);
            box-shadow: 0 0 15px rgba(0,255,0,0.8);
        }
        .score-fill.suspicious {
            background: linear-gradient(90deg, #ff0000 0%, #cc0000 100%);
            box-shadow: 0 0 15px rgba(255,0,0,0.8);
        }
        .reasons {
            margin-top: 20px;
        }
        .reasons h4 {
            font-size: 16px;
            margin-bottom: 10px;
            color: #00ffff;
            text-transform: uppercase;
            letter-spacing: 2px;
            text-shadow: 0 0 5px rgba(0,255,255,0.5);
        }
        .reason-item {
            background: rgba(255,0,0,0.1);
            padding: 12px;
            margin-bottom: 8px;
            border-radius: 0;
            border-left: 4px solid #ff0000;
            font-size: 14px;
            color: #ff6666;
            border: 1px solid rgba(255,0,0,0.3);
            box-shadow: 0 0 5px rgba(255,0,0,0.3);
            font-weight: 600;
        }
        .tip {
            margin-top: 15px;
            padding: 12px;
            background: rgba(255,255,0,0.1);
            border-left: 4px solid #ffff00;
            border-radius: 0;
            font-size: 14px;
            color: #ffff00;
            border: 1px solid rgba(255,255,0,0.3);
            box-shadow: 0 0 10px rgba(255,255,0,0.3);
        }
        .tip strong {
            color: #ffff00;
            text-shadow: 0 0 5px rgba(255,255,0,0.8);
        }
        .loading {
            display: none;
            text-align: center;
            padding: 20px;
            color: #7f8c8d;
        }
        .spinner {
            border: 3px solid #f3f3f3;
            border-top: 3px solid #3498db;
            border-radius: 50%;
            width: 40px;
            height: 40px;
            animation: spin 1s linear infinite;
            margin: 0 auto 10px;
        }
        @keyframes spin {
            0% { transform: rotate(0deg); }
            100% { transform: rotate(360deg); }
        }
        .tabs {
            display: flex;
            border-bottom: 2px solid #00ffff;
            margin-bottom: 20px;
            overflow-x: auto;
            box-shadow: 0 2px 10px rgba(0,255,255,0.3);
            flex-wrap: nowrap;
            white-space: nowrap;
        }
        .tab {
            flex: 1;
            padding: 10px 8px;
            background: rgba(0,255,255,0.1);
            border: none;
            border-bottom: 3px solid transparent;
            cursor: pointer;
            font-size: 11px;
            font-weight: 700;
            color: #00ffff;
            transition: all 0.3s;
            text-transform: uppercase;
            letter-spacing: 0.5px;
            font-family: 'Orbitron', 'Courier New', 'Consolas', 'Monaco', monospace;
            position: relative;
            white-space: nowrap;
            overflow: hidden;
            text-overflow: ellipsis;
        }
        .tab::before {
            content: '';
            position: absolute;
            bottom: 0;
            left: 0;
            width: 0;
            height: 3px;
            background: #00ffff;
            transition: width 0.3s;
            box-shadow: 0 0 10px #00ffff;
        }
        .tab:hover::before {
            width: 100%;
        }
        .tab:hover {
            background: rgba(0,255,255,0.2);
            color: #ffffff;
            text-shadow: 0 0 10px rgba(0,255,255,0.8);
        }
        .tab.active {
            background: rgba(0,255,255,0.3);
            color: #ffffff;
            border-bottom-color: #00ffff;
            text-shadow: 0 0 15px rgba(0,255,255,1);
            box-shadow: inset 0 0 20px rgba(0,255,255,0.2);
        }
        .tab.active::before {
            width: 100%;
        }
        .tab-content {
            display: none;
        }
        .tab-content.active {
            display: block;
        }
        .stat-card {
            background: rgba(0,255,255,0.1);
            padding: 15px;
            border-radius: 0;
            margin-bottom: 10px;
            border: 1px solid #00ffff;
            border-left: 4px solid #00ffff;
            box-shadow: 0 0 10px rgba(0,255,255,0.3);
        }
        .stat-card h4 {
            margin: 0 0 10px 0;
            color: #00ffff;
            font-size: 16px;
            text-transform: uppercase;
            letter-spacing: 1px;
            text-shadow: 0 0 5px rgba(0,255,255,0.5);
        }
        .stat-value {
            font-size: 32px;
            font-weight: 900;
            color: #00ffff;
            font-family: 'Orbitron', 'Courier New', 'Consolas', 'Monaco', monospace;
            text-shadow: 0 0 15px rgba(0,255,255,0.8);
        }
        .quiz-question {
            background: #f8f9fa;
            padding: 15px;
            border-radius: 6px;
            margin-bottom: 15px;
        }
        .quiz-question {
            background: rgba(0,255,255,0.1);
            border: 1px solid #00ffff;
            box-shadow: 0 0 10px rgba(0,255,255,0.3);
        }
        .quiz-question h4 {
            color: #00ffff;
            text-shadow: 0 0 5px rgba(0,255,255,0.5);
        }
        .quiz-option {
            background: rgba(0,0,0,0.5);
            padding: 12px;
            margin: 8px 0;
            border: 1px solid #00ffff;
            border-radius: 0;
            cursor: pointer;
            transition: all 0.3s;
            color: #00ffff;
            font-weight: 600;
        }
        .quiz-option:hover {
            border-color: #ff00ff;
            background: rgba(255,0,255,0.2);
            box-shadow: 0 0 15px rgba(255,0,255,0.5);
            transform: translateX(5px);
        }
        .quiz-option.correct {
            background: rgba(0,255,0,0.2);
            border-color: #00ff00;
            color: #00ff00;
            box-shadow: 0 0 20px rgba(0,255,0,0.6);
        }
        .quiz-option.wrong {
            background: rgba(255,0,0,0.2);
            border-color: #ff0000;
            color: #ff6666;
            box-shadow: 0 0 20px rgba(255,0,0,0.6);
        }
        .learn-section {
            background: rgba(0,255,255,0.1);
            padding: 15px;
            border-radius: 0;
            margin-bottom: 15px;
            border: 1px solid #00ffff;
            box-shadow: 0 0 10px rgba(0,255,255,0.3);
        }
        .learn-section h3 {
            color: #00ffff;
            margin-bottom: 10px;
            text-transform: uppercase;
            letter-spacing: 2px;
            text-shadow: 0 0 10px rgba(0,255,255,0.8);
            font-family: 'Orbitron', 'Courier New', 'Consolas', 'Monaco', monospace;
        }
        .learn-section p {
            color: rgba(255,255,255,0.8);
            line-height: 1.8;
        }
        .challenge-result {
            padding: 15px;
            border-radius: 6px;
            margin-top: 15px;
            font-weight: 600;
        }
        .challenge-result.success {
            background: rgba(0,255,0,0.2);
            border: 2px solid #00ff00;
            color: #00ff00;
            box-shadow: 0 0 20px rgba(0,255,0,0.6);
            text-shadow: 0 0 10px rgba(0,255,0,0.8);
        }
        .challenge-result.fail {
            background: rgba(255,0,0,0.2);
            border: 2px solid #ff0000;
            color: #ff6666;
            box-shadow: 0 0 20px rgba(255,0,0,0.6);
            text-shadow: 0 0 10px rgba(255,0,0,0.8);
        }
        .builder-section {
            background: rgba(0,255,255,0.1);
            padding: 15px;
            border: 1px solid #00ffff;
            border-radius: 0;
            margin-bottom: 20px;
            box-shadow: 0 0 10px rgba(0,255,255,0.3);
        }
        .builder-section h3 {
            color: #00ffff;
            margin-bottom: 15px;
            text-transform: uppercase;
            letter-spacing: 2px;
            text-shadow: 0 0 10px rgba(0,255,255,0.8);
            font-family: 'Orbitron', 'Courier New', 'Consolas', 'Monaco', monospace;
        }
        .keyword-list {
            display: flex;
            flex-wrap: wrap;
            gap: 8px;
            margin-bottom: 15px;
        }
        .keyword-tag {
            background: rgba(0,255,255,0.2);
            border: 1px solid #00ffff;
            padding: 6px 12px;
            border-radius: 0;
            color: #00ffff;
            font-size: 13px;
            display: flex;
            align-items: center;
            gap: 8px;
        }
        .keyword-tag .remove {
            cursor: pointer;
            color: #ff0000;
            font-weight: bold;
        }
        .keyword-tag .remove:hover {
            text-shadow: 0 0 10px rgba(255,0,0,0.8);
        }
        .builder-input {
            width: 100%;
            padding: 10px;
            background: rgba(0,0,0,0.8);
            border: 1px solid #00ffff;
            border-radius: 0;
            color: #00ffff;
            font-family: 'Courier New', monospace;
            margin-bottom: 10px;
        }
        .builder-input:focus {
            outline: none;
            border-color: #ff00ff;
            box-shadow: 0 0 15px rgba(255,0,255,0.5);
        }
        .builder-small-btn {
            padding: 8px 16px;
            background: rgba(0,255,255,0.2);
            border: 1px solid #00ffff;
            color: #00ffff;
            cursor: pointer;
            font-weight: 600;
            text-transform: uppercase;
            font-size: 12px;
            transition: all 0.3s;
        }
        .builder-small-btn:hover {
            background: rgba(0,255,255,0.4);
            box-shadow: 0 0 10px rgba(0,255,255,0.5);
        }
        .scoring-control {
            display: grid;
            grid-template-columns: 1fr 1fr;
            gap: 10px;
            margin-bottom: 15px;
        }
        .scoring-item {
            display: flex;
            align-items: center;
            gap: 10px;
        }
        .scoring-item label {
            flex: 1;
            font-size: 14px;
        }
        .scoring-item input {
            width: 80px;
            padding: 8px;
            background: rgba(0,0,0,0.8);
            border: 1px solid #00ffff;
            color: #00ffff;
            text-align: center;
        }
        .facilitator-panel {
            background: rgba(255,0,0,0.1);
            border: 2px solid #ff0000;
            padding: 20px;
            margin-top: 20px;
            border-radius: 0;
        }
        .facilitator-panel h3 {
            color: #ff0000;
            text-shadow: 0 0 10px rgba(255,0,0,0.8);
        }
    </style>
</head>
<body>
    <div class="container">
        <div style="text-align: center; margin-bottom: 20px;">
            <a href="/" style="display: inline-block; padding: 8px 16px; background: rgba(0,255,255,0.1); border: 1px solid #00ffff; color: #00ffff; text-decoration: none; text-transform: uppercase; font-size: 12px; letter-spacing: 1px; transition: all 0.3s;" onmouseover="this.style.background='rgba(0,255,255,0.2)'; this.style.boxShadow='0 0 10px rgba(0,255,255,0.5)'" onmouseout="this.style.background='rgba(0,255,255,0.1)'; this.style.boxShadow='none'">← BACK TO MENU</a>
        </div>
        <h1>AI PHISHING DETECTOR</h1>
        <p class="subtitle">VAULTGUARD.AI // ACCESS: VAULTGUARD.LOCAL</p>
        
        <div class="tabs">
            <button class="tab active" onclick="switchTab(0)">Analyzer</button>
            <button class="tab" onclick="switchTab(1)">Statistics</button>
            <button class="tab" onclick="switchTab(2)">Challenge</button>
            <button class="tab" onclick="switchTab(3)">Learn</button>
            <button class="tab" onclick="switchTab(4)">Quiz</button>
            <button class="tab" onclick="switchTab(5)">Builder</button>
        </div>
        
        <div id="tab-analyzer" class="tab-content active">
        <h2 style="font-size: 18px; margin-bottom: 15px; color: #2c3e50;">Message Analyzer</h2>
        
        <div class="input-section">
            <label for="message">Enter or paste a message to analyze:</label>
            <textarea id="message" placeholder="Paste a suspicious message here..."></textarea>
        </div>
        
        <div class="samples">
            <h3>Try a sample message:</h3>
            <div class="sample-chips" id="sample-chips">
                <!-- Samples loaded dynamically -->
            </div>
        </div>
        
        <div class="strictness-control">
            <label>Detection Strictness:</label>
            <div class="strictness-buttons">
                <button class="strictness-btn" onclick="setStrictness(0)">Strict</button>
                <button class="strictness-btn active" onclick="setStrictness(1)">Normal</button>
                <button class="strictness-btn" onclick="setStrictness(2)">Lenient</button>
            </div>
        </div>
        
        <div class="button-group">
            <button class="btn-primary" onclick="analyzeMessage()">Analyze Message</button>
            <button class="btn-secondary" onclick="clearMessage()">Clear</button>
        </div>
        
        <div class="loading" id="loading">
            <div class="spinner"></div>
            <div>Analyzing...</div>
        </div>
        
        <div class="results" id="results">
            <div class="verdict" id="verdict"></div>
            <div class="score" id="score"></div>
            <div class="score-bar">
                <div class="score-fill" id="scoreFill"></div>
            </div>
            <div class="reasons" id="reasons"></div>
            <div class="tip">
                <strong>Tip:</strong> Think before you click. When in doubt, verify through official channels.
            </div>
        </div>
        </div>
        
        <div id="tab-statistics" class="tab-content">
            <h2 style="font-size: 18px; margin-bottom: 15px; color: #2c3e50;">Statistics Dashboard</h2>
            <div id="stats-content">Loading statistics...</div>
            <button class="btn-secondary" onclick="loadStats()" style="margin-top: 15px;">Refresh Stats</button>
        </div>
        
        <div id="tab-challenge" class="tab-content">
            <h2 style="font-size: 18px; margin-bottom: 15px; color: #2c3e50;">Challenge Mode</h2>
            <p style="margin-bottom: 15px; color: #7f8c8d;">Try to craft a message that fools the detector! Uses lenient mode for extra challenge.</p>
            <div class="input-section">
                <label for="challenge-message">Your challenge message:</label>
                <textarea id="challenge-message" placeholder="Craft a clever message..."></textarea>
            </div>
            <button class="btn-primary" onclick="challengeMessage()">Test Challenge</button>
            <div id="challenge-result" class="challenge-result" style="display: none;"></div>
        </div>
        
        <div id="tab-learn" class="tab-content">
            <h2 style="font-size: 18px; margin-bottom: 15px; color: #2c3e50;">Learning Center</h2>
            <div class="learn-section">
                <h3>Urgency Language</h3>
                <p>Phishers create urgency to make you act without thinking. Look for words like "urgent", "immediately", "expires today".</p>
            </div>
            <div class="learn-section">
                <h3>Credential Requests</h3>
                <p>Legitimate companies rarely ask you to verify passwords or login credentials via email. Be suspicious of these requests.</p>
            </div>
            <div class="learn-section">
                <h3>Reward Bait</h3>
                <p>If it sounds too good to be true, it probably is. Be wary of unexpected prizes or "you've won" messages.</p>
            </div>
            <div class="learn-section">
                <h3>Impersonation</h3>
                <p>Phishers pretend to be trusted organizations (banks, IT departments, tech companies). Always verify through official channels.</p>
            </div>
            <div class="learn-section">
                <h3>Financial Pressure</h3>
                <p>Scammers create fake invoices, overdue notices, or payment requests. Check your accounts directly, don't click email links.</p>
            </div>
            <div class="learn-section">
                <h3>Suspicious Links</h3>
                <p>Hover over links before clicking. Check if the URL matches the company's official website. Look for misspellings or unusual domains.</p>
            </div>
            <div class="tip" style="margin-top: 20px;">
                <strong>Defender Tips:</strong><br>
                • When in doubt, don't click<br>
                • Verify through official websites or phone numbers<br>
                • Use two-factor authentication when available<br>
                • Keep software updated<br>
                • Think before you act
            </div>
        </div>
        
        <div id="tab-quiz" class="tab-content">
            <h2 style="font-size: 18px; margin-bottom: 15px; color: #00ffff; text-transform: uppercase; letter-spacing: 2px;">Cybersecurity Quiz</h2>
            <p style="margin-bottom: 15px; color: rgba(255,255,255,0.8);">Test your knowledge! Click an answer to see if you're correct.</p>
            <div id="quiz-content">Loading quiz...</div>
        </div>
        
        <div id="tab-builder" class="tab-content">
            <h2 style="font-size: 18px; margin-bottom: 15px; color: #00ffff; text-transform: uppercase; letter-spacing: 2px; font-family: 'Orbitron', monospace;">System Builder</h2>
            <p style="margin-bottom: 20px; color: rgba(255,255,255,0.8);">Customize the phishing detector! Modify keywords, scoring, samples, and more.</p>
            
            <div class="builder-section">
                <h3>Keywords Manager</h3>
                <label>Category:</label>
                <select id="keyword-category" class="builder-input">
                    <option value="0">Urgency Language</option>
                    <option value="1">Credential Requests</option>
                    <option value="2">Reward Bait</option>
                    <option value="3">Impersonation</option>
                    <option value="4">Financial Pressure</option>
                </select>
                <div id="keyword-list" class="keyword-list"></div>
                <div style="display: flex; gap: 10px;">
                    <input type="text" id="new-keyword" class="builder-input" placeholder="Enter new keyword" style="flex: 1;">
                    <button class="builder-small-btn" onclick="addKeyword()">Add</button>
                </div>
                <button class="btn-primary" onclick="saveKeywords()" style="margin-top: 10px;">Save Keywords</button>
            </div>
            
            <div class="builder-section">
                <h3>Sample Messages</h3>
                <div id="sample-list"></div>
                <div style="display: flex; gap: 10px; margin-top: 10px;">
                    <textarea id="new-sample" class="builder-input" placeholder="Enter new sample message" style="min-height: 60px; flex: 1;"></textarea>
                    <button class="builder-small-btn" onclick="addSample()" style="align-self: flex-start;">Add</button>
                </div>
                <button class="btn-primary" onclick="saveSamples()" style="margin-top: 10px;">Save Samples</button>
            </div>
            
            <div class="builder-section">
                <h3>Scoring Weights</h3>
                <p style="color: rgba(255,255,255,0.7); font-size: 14px; margin-bottom: 15px;">Adjust point values for each signal type. Higher = more suspicious. Messages need to reach the threshold (30-55 depending on strictness) to be flagged.</p>
                <div class="scoring-control">
                    <div class="scoring-item">
                        <label title="Words like 'urgent', 'immediately', 'act now' - creates time pressure">Urgency:</label>
                        <input type="number" id="score-urgency" min="0" max="50" value="20" title="Points added when urgency language is detected">
                    </div>
                    <div class="scoring-item">
                        <label title="Requests for passwords, login info, account verification">Credentials:</label>
                        <input type="number" id="score-credential" min="0" max="50" value="25" title="Points added when credential requests are detected">
                    </div>
                    <div class="scoring-item">
                        <label title="Prize announcements, 'you won', free gifts">Reward:</label>
                        <input type="number" id="score-reward" min="0" max="50" value="20" title="Points added when reward bait is detected">
                    </div>
                    <div class="scoring-item">
                        <label title="Pretending to be IT, Microsoft, banks, etc.">Impersonation:</label>
                        <input type="number" id="score-impersonation" min="0" max="50" value="25" title="Points added when impersonation is detected">
                    </div>
                    <div class="scoring-item">
                        <label title="Payment due, invoices, billing issues">Financial:</label>
                        <input type="number" id="score-financial" min="0" max="50" value="25" title="Points added when financial pressure is detected">
                    </div>
                    <div class="scoring-item">
                        <label title="URLs, links, 'click here' - more suspicious when combined with other signals">Links:</label>
                        <input type="number" id="score-link" min="0" max="50" value="15" title="Base points for links. Gets bonus if combined with other signals">
                    </div>
                    <div class="scoring-item">
                        <label title="Extra points when 3+ different signals are detected together">Multi-Signal Bonus:</label>
                        <input type="number" id="score-bonus" min="0" max="20" value="10" title="Bonus points when multiple signals appear together">
                    </div>
                </div>
                <div style="background: rgba(0,255,255,0.1); padding: 10px; margin-top: 15px; border: 1px solid #00ffff;">
                    <p style="color: #00ffff; font-size: 12px; margin: 0;"><strong>Tip:</strong> Hover over labels for explanations. Links get extra points when combined with other signals!</p>
                </div>
                <button class="btn-primary" onclick="saveScoring()">Save Scoring</button>
            </div>
            
            <div class="builder-section">
                <h3>Quiz Builder</h3>
                <div id="quiz-list"></div>
                <div style="margin-top: 15px;">
                    <input type="text" id="quiz-question" class="builder-input" placeholder="Question text">
                    <input type="text" id="quiz-option1" class="builder-input" placeholder="Option A">
                    <input type="text" id="quiz-option2" class="builder-input" placeholder="Option B">
                    <input type="text" id="quiz-option3" class="builder-input" placeholder="Option C">
                    <input type="text" id="quiz-option4" class="builder-input" placeholder="Option D">
                    <select id="quiz-correct" class="builder-input">
                        <option value="0">Correct: A</option>
                        <option value="1">Correct: B</option>
                        <option value="2">Correct: C</option>
                        <option value="3">Correct: D</option>
                    </select>
                    <button class="btn-primary" onclick="addQuizQuestion()" style="margin-top: 10px;">Add Question</button>
                </div>
                <button class="btn-primary" onclick="saveQuiz()" style="margin-top: 10px;">Save Quiz</button>
            </div>
            
            <div class="builder-section">
                <h3>Configuration</h3>
                <button class="btn-secondary" onclick="loadConfig()" style="margin-right: 10px;">Load Current Config</button>
                <button class="btn-secondary" onclick="resetConfig()">Reset to Defaults</button>
            </div>
        </div>
    </div>
    
    <script>
        let samples = [
            "Hi, just wanted to check in and see how you're doing. Hope you're having a great day!",
            "URGENT: Your account will be locked within 24 hours. Click here immediately to verify your identity: http://verify-now.com",
            "Congratulations! You've won a $1000 cash prize! Claim your reward now by clicking this link: www.claimprize.com",
            "This is the IT department. We detected suspicious activity on your account. Please verify your login credentials immediately to prevent account suspension.",
            "Your payment of $299.99 is overdue. Pay now to avoid service interruption. Click here to make payment: pay-now.com",
            "Your package delivery failed. Click here to reschedule: http://delivery-reschedule.net/verify"
        ];
        
        // Load samples from config on page load
        (async function() {
            try {
                const response = await fetch('/config');
                const data = await response.json();
                if (data.samples && data.samples.length > 0) {
                    samples = data.samples;
                }
                updateSampleChips();
            } catch (e) {
                // Use defaults if config fails
                updateSampleChips();
            }
        })();
        
        function updateSampleChips() {
            const chipsDiv = document.getElementById('sample-chips');
            if (!chipsDiv) return;
            
            chipsDiv.innerHTML = '';
            const labels = ['Normal Message', 'Urgent Account', 'Prize Scam', 'IT Impersonation', 'Payment Pressure', 'Suspicious Link'];
            samples.forEach((sample, idx) => {
                const chip = document.createElement('div');
                chip.className = 'sample-chip';
                chip.textContent = labels[idx] || `Sample ${idx + 1}`;
                chip.onclick = () => setSample(idx);
                chipsDiv.appendChild(chip);
            });
        }
        
        let currentStrictness = 1;
        
        function setSample(index) {
            document.getElementById('message').value = samples[index];
        }
        
        function clearMessage() {
            document.getElementById('message').value = '';
            document.getElementById('results').style.display = 'none';
        }
        
        function setStrictness(level) {
            currentStrictness = level;
            const buttons = document.querySelectorAll('.strictness-btn');
            buttons.forEach((btn, idx) => {
                if (idx === level) {
                    btn.classList.add('active');
                } else {
                    btn.classList.remove('active');
                }
            });
            
            // Update strictness on server
            fetch('/strictness', {
                method: 'POST',
                headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
                body: 'level=' + level
            }).catch(err => console.error('Strictness update failed:', err));
        }
        
        async function analyzeMessage() {
            const message = document.getElementById('message').value.trim();
            if (!message) {
                alert('Please enter a message to analyze');
                return;
            }
            
            const loading = document.getElementById('loading');
            const results = document.getElementById('results');
            const analyzeBtn = document.querySelector('.btn-primary');
            
            loading.style.display = 'block';
            results.style.display = 'none';
            analyzeBtn.disabled = true;
            
            try {
                // Send as form data for better compatibility with ESP32 WebServer
                const formData = new URLSearchParams();
                formData.append('message', message);
                
                const response = await fetch('/analyze', {
                    method: 'POST',
                    headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
                    body: formData.toString()
                });
                
                if (!response.ok) {
                    throw new Error('Analysis failed');
                }
                
                const data = await response.json();
                displayResults(data);
            } catch (error) {
                alert('Error analyzing message. Please try again.');
                console.error('Error:', error);
            } finally {
                loading.style.display = 'none';
                analyzeBtn.disabled = false;
            }
        }
        
        function displayResults(data) {
            const results = document.getElementById('results');
            const verdict = document.getElementById('verdict');
            const score = document.getElementById('score');
            const scoreFill = document.getElementById('scoreFill');
            const reasonsDiv = document.getElementById('reasons');
            
            // Set verdict and styling
            const isSuspicious = data.verdict === 'Suspicious';
            verdict.textContent = data.verdict;
            verdict.style.color = isSuspicious ? '#dc3545' : '#28a745';
            results.className = 'results ' + (isSuspicious ? 'suspicious' : 'safe');
            
            // Set score
            score.textContent = data.score + '%';
            scoreFill.style.width = data.score + '%';
            scoreFill.className = 'score-fill ' + (isSuspicious ? 'suspicious' : 'safe');
            
            // Set reasons
            if (data.reasons && data.reasons.length > 0) {
                reasonsDiv.innerHTML = '<h4>Detected Signals:</h4>';
                data.reasons.forEach(reason => {
                    const item = document.createElement('div');
                    item.className = 'reason-item';
                    item.textContent = reason;
                    reasonsDiv.appendChild(item);
                });
            } else {
                reasonsDiv.innerHTML = '<h4>No suspicious signals detected</h4>';
            }
            
            results.style.display = 'block';
        }
        
        function switchTab(index) {
            const tabs = document.querySelectorAll('.tab');
            const contents = document.querySelectorAll('.tab-content');
            
            tabs.forEach((tab, i) => {
                if (i === index) {
                    tab.classList.add('active');
                } else {
                    tab.classList.remove('active');
                }
            });
            
            contents.forEach((content, i) => {
                if (i === index) {
                    content.classList.add('active');
                } else {
                    content.classList.remove('active');
                }
            });
            
            if (index === 1) loadStats();
            if (index === 4) loadQuiz();
            // Lazy load Builder tab only when clicked (faster initial page load)
            if (index === 5 && !builderLoaded) {
                loadBuilder();
                builderLoaded = true;
            }
        }
        
        // Builder functions
        let builderKeywords = {0: [], 1: [], 2: [], 3: [], 4: []};
        let builderSamples = [];
        let builderQuiz = [];
        let builderLoaded = false; // Track if Builder has been loaded
        
        async function loadBuilder() {
            try {
                const response = await fetch('/config');
                const data = await response.json();
                
                // Load keywords
                builderKeywords[0] = data.keywords.urgency || [];
                builderKeywords[1] = data.keywords.credential || [];
                builderKeywords[2] = data.keywords.reward || [];
                builderKeywords[3] = data.keywords.impersonation || [];
                builderKeywords[4] = data.keywords.financial || [];
                updateKeywordList();
                
                // Load samples
                builderSamples = data.samples || [];
                updateSampleList();
                
                // Load scoring
                if (data.scoring) {
                    document.getElementById('score-urgency').value = data.scoring.urgency || 20;
                    document.getElementById('score-credential').value = data.scoring.credential || 25;
                    document.getElementById('score-reward').value = data.scoring.reward || 20;
                    document.getElementById('score-impersonation').value = data.scoring.impersonation || 25;
                    document.getElementById('score-financial').value = data.scoring.financial || 25;
                    document.getElementById('score-link').value = data.scoring.link || 15;
                    document.getElementById('score-bonus').value = data.scoring.bonus || 10;
                }
                
                // Load quiz
                builderQuiz = data.quiz || [];
                updateQuizList();
            } catch (error) {
                console.error('Error loading config:', error);
            }
        }
        
        function updateKeywordList() {
            const category = parseInt(document.getElementById('keyword-category').value);
            const list = document.getElementById('keyword-list');
            list.innerHTML = '';
            
            builderKeywords[category].forEach((keyword, idx) => {
                const tag = document.createElement('div');
                tag.className = 'keyword-tag';
                tag.innerHTML = keyword + ' <span class="remove" onclick="removeKeyword(' + category + ', ' + idx + ')">×</span>';
                list.appendChild(tag);
            });
        }
        
        document.getElementById('keyword-category').addEventListener('change', updateKeywordList);
        
        function addKeyword() {
            const category = parseInt(document.getElementById('keyword-category').value);
            const keyword = document.getElementById('new-keyword').value.trim();
            if (keyword) {
                builderKeywords[category].push(keyword);
                document.getElementById('new-keyword').value = '';
                updateKeywordList();
            }
        }
        
        function removeKeyword(category, index) {
            builderKeywords[category].splice(index, 1);
            updateKeywordList();
        }
        
        async function saveKeywords() {
            const category = parseInt(document.getElementById('keyword-category').value);
            const keywords = builderKeywords[category].join(',');
            
            try {
                const formData = new URLSearchParams();
                formData.append('category', category);
                formData.append('keywords', keywords);
                
                const response = await fetch('/config/keywords', {
                    method: 'POST',
                    headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
                    body: formData.toString()
                });
                
                if (response.ok) {
                    alert('Keywords saved!');
                } else {
                    alert('Error saving keywords');
                }
            } catch (error) {
                alert('Error saving keywords');
                console.error(error);
            }
        }
        
        function updateSampleList() {
            const list = document.getElementById('sample-list');
            list.innerHTML = '';
            
            builderSamples.forEach((sample, idx) => {
                const item = document.createElement('div');
                item.className = 'keyword-tag';
                item.style.marginBottom = '8px';
                item.innerHTML = sample.substring(0, 50) + (sample.length > 50 ? '...' : '') + 
                    ' <span class="remove" onclick="removeSample(' + idx + ')">×</span>';
                list.appendChild(item);
            });
        }
        
        function addSample() {
            const sample = document.getElementById('new-sample').value.trim();
            if (sample) {
                builderSamples.push(sample);
                document.getElementById('new-sample').value = '';
                updateSampleList();
            }
        }
        
        function removeSample(index) {
            builderSamples.splice(index, 1);
            updateSampleList();
        }
        
        async function saveSamples() {
            try {
                const formData = new URLSearchParams();
                formData.append('samples', builderSamples.join('|||'));
                
                const response = await fetch('/config/samples', {
                    method: 'POST',
                    headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
                    body: formData.toString()
                });
                
                if (response.ok) {
                    alert('Samples saved!');
                    // Update samples array for analyzer
                    samples.length = 0;
                    builderSamples.forEach(s => samples.push(s));
                    updateSampleChips();
                } else {
                    alert('Error saving samples');
                }
            } catch (error) {
                alert('Error saving samples');
                console.error(error);
            }
        }
        
        async function saveScoring() {
            try {
                const formData = new URLSearchParams();
                formData.append('urgency', document.getElementById('score-urgency').value);
                formData.append('credential', document.getElementById('score-credential').value);
                formData.append('reward', document.getElementById('score-reward').value);
                formData.append('impersonation', document.getElementById('score-impersonation').value);
                formData.append('financial', document.getElementById('score-financial').value);
                formData.append('link', document.getElementById('score-link').value);
                formData.append('bonus', document.getElementById('score-bonus').value);
                
                const response = await fetch('/config/scoring', {
                    method: 'POST',
                    headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
                    body: formData.toString()
                });
                
                if (response.ok) {
                    alert('Scoring saved!');
                } else {
                    alert('Error saving scoring');
                }
            } catch (error) {
                alert('Error saving scoring');
                console.error(error);
            }
        }
        
        function updateQuizList() {
            const list = document.getElementById('quiz-list');
            list.innerHTML = '';
            
            builderQuiz.forEach((q, idx) => {
                try {
                    const question = JSON.parse(q);
                    const item = document.createElement('div');
                    item.className = 'keyword-tag';
                    item.style.marginBottom = '8px';
                    item.innerHTML = question.question + ' <span class="remove" onclick="removeQuiz(' + idx + ')">×</span>';
                    list.appendChild(item);
                } catch (e) {
                    // Skip invalid JSON
                }
            });
        }
        
        function addQuizQuestion() {
            const question = document.getElementById('quiz-question').value.trim();
            const opt1 = document.getElementById('quiz-option1').value.trim();
            const opt2 = document.getElementById('quiz-option2').value.trim();
            const opt3 = document.getElementById('quiz-option3').value.trim();
            const opt4 = document.getElementById('quiz-option4').value.trim();
            const correct = parseInt(document.getElementById('quiz-correct').value);
            
            if (question && opt1 && opt2 && opt3 && opt4) {
                const q = {
                    id: builderQuiz.length + 1,
                    question: question,
                    options: [opt1, opt2, opt3, opt4],
                    correct: correct
                };
                builderQuiz.push(JSON.stringify(q));
                
                document.getElementById('quiz-question').value = '';
                document.getElementById('quiz-option1').value = '';
                document.getElementById('quiz-option2').value = '';
                document.getElementById('quiz-option3').value = '';
                document.getElementById('quiz-option4').value = '';
                document.getElementById('quiz-correct').value = '0';
                
                updateQuizList();
            }
        }
        
        function removeQuiz(index) {
            builderQuiz.splice(index, 1);
            updateQuizList();
        }
        
        async function saveQuiz() {
            try {
                const formData = new URLSearchParams();
                formData.append('questions', builderQuiz.join('|||'));
                
                const response = await fetch('/config/quiz', {
                    method: 'POST',
                    headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
                    body: formData.toString()
                });
                
                if (response.ok) {
                    alert('Quiz saved!');
                } else {
                    alert('Error saving quiz');
                }
            } catch (error) {
                alert('Error saving quiz');
                console.error(error);
            }
        }
        
        async function loadConfig() {
            await loadBuilder();
            alert('Configuration loaded!');
        }
        
        async function resetConfig() {
            if (confirm('Reset all configurations to defaults?')) {
                try {
                    const response = await fetch('/config/reset', { method: 'POST' });
                    if (response.ok) {
                        await loadBuilder();
                        alert('Configuration reset!');
                    }
                } catch (error) {
                    alert('Error resetting configuration');
                }
            }
        }
        
        async function loadStats() {
            try {
                const response = await fetch('/stats');
                const data = await response.json();
                
                const statsDiv = document.getElementById('stats-content');
                statsDiv.innerHTML = `
                    <div class="stat-card">
                        <h4>Total Messages Analyzed</h4>
                        <div class="stat-value">${data.totalAnalyzed}</div>
                    </div>
                    <div class="stat-card">
                        <h4>Safe Messages</h4>
                        <div class="stat-value">${data.safeCount}</div>
                    </div>
                    <div class="stat-card">
                        <h4>Suspicious Messages</h4>
                        <div class="stat-value">${data.suspiciousCount}</div>
                    </div>
                    <div class="stat-card">
                        <h4>Phishing Signals Detected</h4>
                        <p>Urgency: ${data.urgencyCount}</p>
                        <p>Credentials: ${data.credentialCount}</p>
                        <p>Rewards: ${data.rewardCount}</p>
                        <p>Impersonation: ${data.impersonationCount}</p>
                        <p>Financial: ${data.financialCount}</p>
                        <p>Links: ${data.linkCount}</p>
                    </div>
                    <div class="stat-card">
                        <h4>Challenge Mode</h4>
                        <p>Attempts: ${data.challengeAttempts}</p>
                        <p>Successes: ${data.challengeSuccesses}</p>
                    </div>
                `;
            } catch (error) {
                console.error('Error loading stats:', error);
            }
        }
        
        async function challengeMessage() {
            const message = document.getElementById('challenge-message').value.trim();
            if (!message) {
                alert('Please enter a message for the challenge');
                return;
            }
            
            try {
                const formData = new URLSearchParams();
                formData.append('message', message);
                
                const response = await fetch('/challenge', {
                    method: 'POST',
                    headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
                    body: formData.toString()
                });
                
                const data = await response.json();
                const resultDiv = document.getElementById('challenge-result');
                
                if (data.challengeSuccess) {
                    resultDiv.className = 'challenge-result success';
                    resultDiv.innerHTML = `Success! You ${data.challengeType === 'fooled' ? 'fooled' : 'triggered a false positive'} the detector!<br>Score: ${data.score}%`;
                } else {
                    resultDiv.className = 'challenge-result fail';
                    resultDiv.innerHTML = `Not this time! The detector caught it.<br>Verdict: ${data.verdict}, Score: ${data.score}%`;
                }
                resultDiv.style.display = 'block';
                loadStats();
            } catch (error) {
                alert('Error in challenge mode');
                console.error(error);
            }
        }
        
        async function loadQuiz() {
            try {
                const response = await fetch('/quiz');
                const data = await response.json();
                const quizDiv = document.getElementById('quiz-content');
                
                if (!data.questions || data.questions.length === 0) {
                    quizDiv.innerHTML = '<p style="color: rgba(255,255,255,0.8);">No quiz questions available. Add some in the Builder tab!</p>';
                    return;
                }
                
                let html = '';
                data.questions.forEach((q, idx) => {
                    let questionObj;
                    if (typeof q === 'string') {
                        try {
                            questionObj = JSON.parse(q);
                        } catch (e) {
                            return; // Skip invalid JSON
                        }
                    } else {
                        questionObj = q;
                    }
                    
                    html += `
                        <div class="quiz-question">
                            <h4>${idx + 1}. ${questionObj.question}</h4>
                            ${questionObj.options.map((opt, optIdx) => `
                                <div class="quiz-option" onclick="checkAnswer(${idx}, ${optIdx}, ${questionObj.correct})">
                                    ${String.fromCharCode(65 + optIdx)}. ${opt}
                                </div>
                            `).join('')}
                            <div id="quiz-result-${idx}" style="margin-top: 10px; font-weight: 600;"></div>
                        </div>
                    `;
                });
                quizDiv.innerHTML = html;
            } catch (error) {
                console.error('Error loading quiz:', error);
                document.getElementById('quiz-content').innerHTML = '<p style="color: rgba(255,255,255,0.8);">Error loading quiz. Try refreshing.</p>';
            }
        }
        
        function checkAnswer(qIdx, selected, correct) {
            const resultDiv = document.getElementById(`quiz-result-${qIdx}`);
            const options = document.querySelectorAll(`#quiz-content .quiz-question:nth-child(${qIdx + 1}) .quiz-option`);
            
            options.forEach((opt, idx) => {
                opt.onclick = null;
                if (idx === correct) {
                    opt.classList.add('correct');
                } else if (idx === selected && idx !== correct) {
                    opt.classList.add('wrong');
                }
            });
            
            if (selected === correct) {
                resultDiv.innerHTML = '<span style="color: #28a745;">Correct! Well done!</span>';
            } else {
                resultDiv.innerHTML = '<span style="color: #dc3545;">Not quite. The correct answer is ' + String.fromCharCode(65 + correct) + '.</span>';
            }
        }
    </script>
</body>
</html>
)rawliteral";

#endif
