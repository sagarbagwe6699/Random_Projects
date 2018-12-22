import React, { Component } from 'react';
import logo from './logo.svg';
import './App.css';

class App extends Component {
  state={
    val: "Hello"
  }
  handleOnClick=()=>{
    this.setState({val:"Clicked"});
  };
  render() {
    return (
      <div>
        {this.state.val}
        <button onClick={this.handleOnClick}>ClickMe</button>
      </div>
    );
  }
}

export default App;
