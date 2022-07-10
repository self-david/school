import React from 'react';
import { BrowserRouter, Route, Switch } from 'react-router-dom';
import Index from './Components/Index';
import Show from './Components/Show';
import NotFound from './Components/NotFound';

function App() {
  return(
    <BrowserRouter>
      <Switch>
        <Route exact path="/" component={Index} />
        <Route exact path="/FCFS" component={Index} />
        <Route exact path="/FCFS/show" component={Show} />
        <Route component={NotFound}/>
      </Switch>
    </BrowserRouter>
  );
}


export default App;