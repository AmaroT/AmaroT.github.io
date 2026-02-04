// Load saved cards from localStorage on page load
function loadCards() {
    const columns = ['backlog', 'todo', 'inprogress', 'done'];
    columns.forEach(col => {
      const container = document.getElementById(col).querySelector('.cards');
      container.innerHTML = ''; // Clear existing cards
      const saved = JSON.parse(localStorage.getItem(col) || '[]');
      saved.forEach(text => {
        createCard(container, text);
      });
    });
    updateProgress();
  }
  
  // Create a new card
  function createCard(container, text = '') {
    const card = document.createElement('div');
    card.className = 'card';
    card.draggable = true;
    card.innerHTML = `
      <span contenteditable="true">${text || 'New Task'}</span>
      <button onclick="deleteCard(this)">X</button>
    `;
    
    // Attach drag events
    card.addEventListener('dragstart', drag);
    container.appendChild(card);
    updateProgress();
  }
  
  // Add new card to column
  function addCard(columnId) {
    const container = document.getElementById(columnId).querySelector('.cards');
    createCard(container);
  }
  
  // Delete card
  function deleteCard(btn) {
    btn.parentElement.remove();
    saveAllCards();
    updateProgress();
  }
  
  // Drag start – store the dragged card reference
  let draggedCard = null;
  
  function drag(ev) {
    draggedCard = ev.target.closest('.card'); // Store the actual card being dragged
    ev.dataTransfer.setData("text/plain", ""); // Required for Firefox
    ev.dataTransfer.effectAllowed = "move";
  }
  
  // Allow drop
  function allowDrop(ev) {
    ev.preventDefault();
    ev.dataTransfer.dropEffect = "move";
  }
  
  // Drop handler – move the original card
  function drop(ev) {
    ev.preventDefault();
    
    if (!draggedCard) return;
    
    // Find the target cards container
    const targetContainer = ev.target.closest('.cards');
    if (!targetContainer) return;
  
    // Append the original dragged card to new location
    targetContainer.appendChild(draggedCard);
    
    // Ensure it's visible and draggable again
    draggedCard.style.display = "block";
    draggedCard.draggable = true;
  
    // Clear dragged reference
    draggedCard = null;
  
    // Save and update progress
    saveAllCards();
    updateProgress();
  }
  
  // Save all cards to localStorage
  function saveAllCards() {
    const columns = ['backlog', 'todo', 'inprogress', 'done'];
    columns.forEach(col => {
      const cards = [];
      document.getElementById(col).querySelectorAll('.card span').forEach(span => {
        cards.push(span.innerText.trim());
      });
      localStorage.setItem(col, JSON.stringify(cards));
    });
  }
  
  // Update progress percentage
  function updateProgress() {
    const total = document.querySelectorAll('.card').length;
    const done = document.querySelectorAll('#done .card').length;
    const percent = total === 0 ? 0 : Math.round((done / total) * 100);
    document.getElementById('progress').innerText = percent + '%';
  }
  
  // Load cards when page opens
  window.onload = loadCards;