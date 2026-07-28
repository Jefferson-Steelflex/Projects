// Event Listeners and Handlers Practice
// Listens for specific events to create interactive behavior
// 1. Click Event: Changes box color and text on click
// 2. Mouseover Event: Changes box color and text on hover
// 3. Mouseout Event: Reverts box color and text when mouse leaves
// .addEventListener(event, callback(function)) 
//
//
//
const grid = document.querySelector(".Dino-Grid");
const infoPanel = document.querySelector(".Dino-Info");

const nameEl = infoPanel.querySelector(".Dino-Name");
const eraEl = infoPanel.querySelector(".era");
const familyEl = infoPanel.querySelector(".family");
const genusEl = infoPanel.querySelector(".genus");
const heightEl = infoPanel.querySelector(".height");
const weightEl = infoPanel.querySelector(".weight");
const lengthEl = infoPanel.querySelector(".length");
const dietEl = infoPanel.querySelector(".diet");

const descriptionEl = infoPanel.querySelector(".description");
const discoveryEl = infoPanel.querySelector(".discovery");
const paleoecologyEl = infoPanel.querySelector(".paleoecology");

const imageEl = infoPanel.querySelector(".Dino-Image-Large");

const dinonoise = new Audio("audio/ClickSound.wav");


// Back Button Event Listener
document.getElementById("Back-Button").addEventListener("click", () => {
    
    // Toggle Visibility (On-Off)
    infoPanel.classList.add("hidden");
    grid.classList.remove("hidden");
});


document.querySelectorAll(".Dino-Card").forEach(card => {
    card.addEventListener("click", () => {
        const data = card.querySelector(".Dino-Data").dataset;

        //audio for click 
        dinonoise.currentTime = 0;
        dinonoise.play();


        // Toggle Visibility (On-Off)
        grid.classList.add("hidden");
        infoPanel.classList.remove("hidden");

        //Fill Panel with Data
        nameEl.textContent = card.dataset.name;
        eraEl.textContent = data.era;
        familyEl.textContent = data.family;
        genusEl.textContent = data.genus;
        heightEl.textContent = data.height;
        weightEl.textContent = data.weight;
        lengthEl.textContent = data.length;
        dietEl.textContent = data.diet;

        descriptionEl.textContent = data.description;
        discoveryEl.textContent = data.discovery;
        paleoecologyEl.textContent = data.paleoecology;

        imageEl.src = data.image;
        imageEl.alt = card.dataset.name;
    });
}); 
